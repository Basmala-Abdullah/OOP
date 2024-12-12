#include <iostream>
#include <string>
using namespace std;

class Data {
public:
    ~Data() {}
    virtual void display()=0;
};


template <typename T>
class DataHolder:public Data {
private:
    T value;

public:
    DataHolder(T val){
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
    Data** items;

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
        Data** newList = new Data*[size+1];
        for (int i=0;i<size; ++i) {
            newList[i]=items[i];
        }
        newList[size]=new DataHolder<T>(value);
        delete[] items;
        items = newList;
        size++;
    }

    bool pop(Data** poppedValue) {
        if (size == 0) {
            return false;
        }

        *poppedValue=items[size - 1];
        Data** newList = new Data*[size - 1];
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
            Data* poppedValue;
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
