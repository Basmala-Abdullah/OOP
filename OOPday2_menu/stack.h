#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "neededFunctions.h"

#define PUSH_OPTION 0
#define POP_OPTION 1
#define PRINT_OPTION 2



class Stack{

    int top;
    int size;
    Employee *employees;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        employees = new Employee[size];
    }

    int push(Employee e){
        if(top == size-1){
            return 0;
        }
        top++;
        employees[top]=e;
        return 1;
    }

    int pop(Employee *eMain){

        if(top == -1){
            return 0;
        }
        Employee e=employees[top];
        top--;
        *eMain=e;
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

    void emptyTheStack(){
        while(!isEmpty()){
            Employee e;
            this->pop(&e);
        }

    }


    ~Stack(){
        delete [] employees;
        //cout<<"\nSuccessfully deleted the stack"<<endl;
    }
};



void color_option(int option);
void initial_state(int option);
void stack_cpy_inReverse(Stack *dest, Stack *src);
#endif // STACK_H_INCLUDED
