#include "stack.h"



void color_option(int option){
    system("cls");
    if(option == PUSH_OPTION){
        printf(BLUE"Push\033[0m\n");
        printf(RESET"Pop\033[0m\n");
        printf(RESET"Print\033[0m\n");

    }else if(option == POP_OPTION){
        printf(RESET"Push\033[0m\n");
        printf(BLUE"Pop\033[0m\n");
        printf(RESET"Print\033[0m\n");
    }
    else if(option == PRINT_OPTION){
        printf(RESET"Push\033[0m\n");
        printf(RESET"Pop\033[0m\n");
        printf(BLUE"Print\033[0m\n");
    }
}

void initial_state(int option){
    system("cls");
    forColoringText();
    color_option(option);
}


void stack_cpy_inReverse(Stack *dest, Stack *src){
    Employee buffer;
    while(!(src->isEmpty())){
        src->pop(&buffer);
        dest->push(buffer);
    }
}
