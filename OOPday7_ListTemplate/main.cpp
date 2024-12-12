#include <iostream>

using namespace std;

template <typename T>
class List{

    int top;
    int size;
    T *items;
    T *buffer;

public:
    List(){
        top=-1;
        size=0;
    }

    void push(T data){
        if(size!=0){
            buffer = new T[size];
            for(int i=0;i<size;i++){
                buffer[i]=items[i];
            }
            delete[] items;
        }
        size++;
        items = new T[size];
        if(size!=1){
            for(int i=0;i<size-1;i++){
                items[i]=buffer[i];
            }
            delete []buffer;
        }
        items[size-1]=data;
    }

    int pop(T *dataMain){
        if(size==0){
            return 0;
        }

        *dataMain = items[size-1];
        buffer = new T[size-1];
        for(int i=0;i<size-1;i++){
            buffer[i]=items[i];
        }
        delete[] items;
        size--;
        items = new T[size];
        for(int i=0;i<size;i++){
            items[i]=buffer[i];
        }
        delete []buffer;
        return 1;

    }
    void printList() {
        for (int i = 0; i <size; i++) {
            cout<<items[i]<<" ";
        }
        cout <<endl;
    }


    ~List() {

        delete[] items;
    }

};



int main()
{

    List<int> myList;


int cont=1;
    while(cont){
        int choice;

        cout<<"Enter:\n1 for pushing\n2 for poping\n3 To Exit"<<endl;
        scanf("%d", &choice);
        if(choice == 1){
            int value;
            cout<<"Enter value you want to push: ";
            scanf("%d", &value);
            myList.push(value);
            cout<<"Your list after push: ";
            myList.printList();
            cout<<endl;
        }else if(choice == 2){
            int poppedValue;
            if (myList.pop(&poppedValue)) {
                cout<<"Popped value: "<< poppedValue<<endl;
                cout<<"My list after pop: ";
                myList.printList();
            } else {
                cout<<"Pop failed: List is empty"<<endl;
            }
        }else if(choice == 3){
            return 0;
        }


    }
    return 0;
}
