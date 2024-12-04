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




    Stack& operator=(Stack &s){
        if (this == &s) {
            //if self-assignment
            return *this;
        }
        //freeing the existing employees -> 3shan momkin ykon el stack ely b3milha equal already liha list of employees
        if(this->items != NULL){
            delete[] items;
        }

        this->size = s.size;
        this->top = s.top;
        this->items = new int[s.size];

        for(int i=0;i<size;i++){
            this->items[i] = s.items[i];
        }

        return *this;
    }

    void viewContentCallByRef(Stack &s){
        //Stack buffer(s.size);
        //buffer=s;
        while(!s.isEmpty()){
            int content;
            s.pop(&content);
            cout<<content<<endl;
        }
    }

    void viewContentCallByValue(Stack s){

        while(!s.isEmpty()){
            int content;
            s.pop(&content);
            cout<<content<<endl;;
        }
    }

    Stack(Stack &s){
        cout<<"Copy Constructor is called"<<endl;
        this->size = s.size;
        this->top = s.top;
        this->items = new int[s.size];

        for(int i=0;i<size;i++){
            this->items[i] = s.items[i];
        }
    }

    ~Stack(){
        delete [] items;
        cout<<"\nSuccessfully deleted the stack"<<endl;
    }
};


int Stack::noOfStacks = 0;

int main()
{
    cout << "Enter Size of the stack1:" << endl;
    int size;
    cin>>size;


    Stack stack1(size);

    stack1.push(5);
    stack1.push(5);
    stack1.push(5);

    stack1.viewContentCallByValue(stack1);


    return 0;
}
