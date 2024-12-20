#include <iostream>
#include <string>
using namespace std;

class Value {
public:
    ~Value() {}
    virtual void display()=0;
};


template <typename T>
class ValueContent:public Value {
private:
    T value;

public:
    ValueContent(T val){
        value=val;
    }
    void display() {
        cout<<value<<" ";
    }
    T getValue() const {
        return value;
    }
};

class List{
private:
    int size;
    Value** items;

public:
    List(){
        size=0;
        items = nullptr;
    }

    ~List(){
        for (int i=0;i<size;++i) {
            delete items[i];
        }
        delete[] items;
    }

    template <typename T>
    void push(T value){
        Value** newList = new Value*[size+1];
        for (int i=0;i<size; ++i) {
            newList[i]=items[i];
        }
        newList[size]=new ValueContent<T>(value);
        delete[] items;
        items = newList;
        size++;
    }

    bool pop(Value** poppedValue) {
        if (size == 0) {
            return false;
        }

        *poppedValue=items[size - 1];
        Value** newList = new Value*[size - 1];
        for (int i = 0; i < size - 1; ++i) {
            newList[i] = items[i];
        }
        delete[] items;
        items = newList;
        size--;
        return true;
    }

    void printList() {
        for (int i = 0; i < size; ++i) {
            items[i]->display();
        }
        cout<<endl;
    }
};

int main() {
    List myList;
    int cont = 1;

    while (cont) {
        int choice;

        cout<<"Enter:\n1 for pushing\n2 for popping\n3 to Exit" << endl;
        cin>>choice;

        if (choice == 1) {
            cout<<"Enter value you want to push: ";
            string value;
            cin>>value;
            if (isdigit(value[0])) {
                myList.push(stoi(value));
            }else{
                myList.push(value);
            }

            cout<<"Your list after push: ";
            myList.printList();
        } else if (choice == 2) {
            Value* poppedValue;
            if (myList.pop(&poppedValue)) {
                cout << "Popped value: ";
                poppedValue->display();
                cout<<endl;

                cout<<"My list after pop: ";
                myList.printList();
            } else {
                cout<<"Pop failed: List is empty"<<endl;
            }
        } else if (choice==3) {
            return 0;
        }
    }
    return 0;
}
