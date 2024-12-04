#include <iostream>

using namespace std;

class List{

    int top;
    int size;
    int *items;
    int *buffer;

public:
    List(){
        top=-1;
        size=0;
    }

    void push(int data){
        if(size!=0){
            buffer = new int[size];
            for(int i=0;i<size;i++){
                buffer[i]=items[i];
            }
            delete[] items;
        }
        size++;
        items = new int[size];
        if(size!=1){
            for(int i=0;i<size-1;i++){
                items[i]=buffer[i];
            }
            delete []buffer;
        }
        items[size-1]=data;
    }

    int pop(int *dataMain){
        if(size==0){
            return 0;
        }

        *dataMain = items[size-1];
        buffer = new int[size-1];
        for(int i=0;i<size-1;i++){
            buffer[i]=items[i];
        }
        delete[] items;
        size--;
        items = new int[size];
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

    List myList;

/*
    myList.push(10);
    myList.push(20);
    myList.push(30);
    cout<<"My list after pushes: ";
    myList.printList();

    int poppedValue;
    if (myList.pop(&poppedValue)) {
        cout<<"Popped value: "<< poppedValue<<endl;
    } else {
        cout<<"Pop failed: List is empty"<<endl;
    }

    cout<<"My list after pop: ";
    myList.printList();


    myList.push(40);
    myList.push(50);
    cout <<"My list after more pushes: ";
    myList.printList();

    cout<<"My list after more poping: ";
    while(myList.pop(&poppedValue)) {
        cout<<"Popped value: "<< poppedValue<<endl;
    }
    cout<<"My List is now empty"<<endl;
    */
int cont=1;
    while(cont){
        int choice;

        cout<<"Enter:\n1 for pushing\n2 for poping"<<endl;
        scanf("%d", &choice);
        if(choice == 1){
            int value;
            cout<<"Enter value you want to push: ";
            scanf("%d", &value);
            myList.push(value);
            cout<<"Your list after push: ";
            myList.printList();
        }else if(choice == 2){
            int poppedValue;
            if (myList.pop(&poppedValue)) {
                cout<<"Popped value: "<< poppedValue<<endl;
                cout<<"My list after pop: ";
                myList.printList();
            } else {
                cout<<"Pop failed: List is empty"<<endl;
            }
        }


    }
    return 0;
}
