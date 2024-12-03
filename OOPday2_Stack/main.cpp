#include <iostream>

using namespace std;


class Stack{
    int top;
    int size;
    int *items;
    static int noOfStacks;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        items = new int[size];
        noOfStacks++;
    }

    int push(int data){
        if(top == size-1){
            return 0;
        }
        top++;
        items[top]=data;

        return 1;
    }

    int pop(int *dataMain){

        if(top == -1){
            return 0;
        }
        int data=items[top];
        top--;
        *dataMain=data;

        return 1;
    }

    ~Stack(){
        delete [] items;
        cout<<"\nSuccessfully deleted the stack"<<endl;
    }
};


int Stack::noOfStacks = 0;

int main()
{
    cout << "Enter Size of the stack:" << endl;
    int size;
    cin>>size;


    Stack employeeStack(size);



    return 0;
}
