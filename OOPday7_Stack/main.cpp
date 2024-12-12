#include <iostream>

using namespace std;

template <typename T>
class Stack{
    int top;
    int size;
    T* items;
    static int noOfStacks;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        items = new int[size];
        noOfStacks++;
    }

    int push(T data){
        if(top == size-1){
            return 0;
        }
        top++;
        items[top]=data;

        return 1;
    }

    int pop(T *dataMain){

        if(top == -1){
            return 0;
        }
        int data=items[top];
        top--;
        *dataMain=data;

        return 1;
    }

    int isEmpty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int isFull(){
        if(top == size-1){
            return 1;
        }
        else{
            return 0;
        }
    }

    void viewContent(Stack &s){
        //Stack buffer(s.size);
        //buffer=s;
        while(!s.isEmpty()){
            T content;
            s.pop(&content);
            cout<<content<<endl;
        }
    }

    ~Stack(){
        delete [] items;
        cout<<"\nSuccessfully deleted the stack"<<endl;
    }

};

template <typename T>
int Stack<T>::noOfStacks=0;

int main()
{
    cout << "Enter Size of the stack:" << endl;
    int size;
    cin>>size;


    Stack<int> stack1(size);

    stack1.push(5);
    stack1.push(5);
    stack1.push(5);

    stack1.viewContent(stack1);

    return 0;
}
