
#include "stack.h"
#include "string_operations.h"
void myMenu(){
    forColoringText();

    cout << "Enter Size of the stack:" << endl;
    int size;
    cin>>size;
    if(!(cin_isPositiveNumInput(size))){
        return;
    }
    Stack employeeStack(size);
    Stack buffer(size);

    int curr_option = PUSH_OPTION;
    initial_state(PUSH_OPTION);
    while(1){
        char ch=0;
        ch=getch();
        if(ch == EXTEND_KEY){
            ch=getch();
            switch(ch){
                case 72: //UP
                    switch (curr_option){
                        case PUSH_OPTION:
                            curr_option = PRINT_OPTION;
                            system("cls");
                            color_option(PRINT_OPTION);
                        break;
                         case POP_OPTION:
                            curr_option = PUSH_OPTION;
                            system("cls");
                            color_option(PUSH_OPTION);
                        break;
                        case PRINT_OPTION:
                            curr_option = POP_OPTION;
                            system("cls");
                            color_option(POP_OPTION);
                        break;
                         default:
                            ;
                    }
                    break;
                case 71: //Home
                    break;
                case 79: //End
                    break;
                case 80: //Down
                    switch (curr_option){
                        case PUSH_OPTION:
                            curr_option = POP_OPTION;
                            system("cls");
                            color_option(POP_OPTION);
                        break;
                         case POP_OPTION:
                            curr_option = PRINT_OPTION;
                            system("cls");
                            color_option(PRINT_OPTION);
                        break;
                        case PRINT_OPTION:
                            curr_option = PUSH_OPTION;
                            system("cls");
                            color_option(PUSH_OPTION);
                        break;
                         default:
                            ;
                    }
                    break;
                default:
                    ;


            }
        }
        else{
            switch(ch){

            case 27: //Exit
                return;
                break;
            case 13: //Enter
                switch (curr_option){
                    case PUSH_OPTION:
                        //enterNewEmployeeData();

                        //PUSH
                        system("cls");
                        Employee ePush;
                        int code;
                        char name[20];
                        int salary;
                        if(!(employeeStack.isFull())){
                            int valid=1;
                            cout<<"Enter Employee Data:"<<endl;
                            cout<<"Employee Code-> "; cin>>code;
                            if(!(cin_isPositiveNumInput(code))){
                                valid=0;
                            }
                            Employee ebuffer;
                            buffer.emptyTheStack();
                            while(valid && !(employeeStack.isEmpty()) ){
                                employeeStack.pop(&ebuffer);
                                if(ebuffer.code == code){
                                    printf(RED"Employee Already Exists\n"RESET);
                                    valid=0;
                                    employeeStack.push(ebuffer);
                                }
                                else{
                                    buffer.push(ebuffer);
                                }
                            }
                            if(valid){
                                stack_cpy_inReverse(&employeeStack,&buffer);
                                printf("Employee Name-> ");
                                scanf("\n%[^\n]s",name);

                                if(!contains_only_characters(name)){
                                    printf(RED"Name is invalid, only characters\n"RESET);
                                    valid =0;
                                }
                            }
                            if(valid){

                                cout<<"Employee Salary-> "; cin>>salary;
                                if(!(cin_isPositiveNumInput(salary))){
                                    valid=0;
                                }
                            }
                            if(valid){
                                  ePush.code=code;
                                  ePush.salary=salary;
                                  my_strcpy(ePush.name,name,20);
                                employeeStack.push(ePush);
                                printf(GREEN "Employee Data is Saved Successfully!\n" RESET);
                            }

                        }
                        else{
                            printf(RED"Stack is full\n"RESET);
                        }
                        halt_untilESC();
                        initial_state(PUSH_OPTION);
                    break;
                     case POP_OPTION:
                        system("cls");
                        Employee ePOP;
                        if(employeeStack.pop(&ePOP)){
                            cout<<"Employee Data:"<<endl;
                            cout<<"Employee Code-> "<<ePOP.code<<endl;
                            cout<<"Employee Name-> "<<ePOP.name<<endl;
                            cout<<"Employee Salary-> "<<ePOP.salary<<endl;
                            printf(GREEN "\nThis Employee Data is Deleted!\n" RESET);
                        }
                        else{
                            printf(RED"No Employees\n"RESET);
                        }
                        halt_untilESC();
                        initial_state(POP_OPTION);
                    break;
                     case PRINT_OPTION:
                         //PRINT
                         system("cls");

                         Employee ePrint;
                         stack_cpy_inReverse(&buffer,&employeeStack);
                         if(!(buffer.isEmpty())){
                            cout<<"Employees Data:"<<endl;
                            while(!(buffer.isEmpty())){
                                buffer.pop(&ePrint);
                                cout<<"Employee Code-> "<<ePrint.code<<endl;
                                cout<<"Employee Name-> "<<ePrint.name<<endl;
                                cout<<"Employee Salary-> "<<ePrint.salary<<endl;
                                cout<<"-----------------------------------------"<<endl;
                                employeeStack.push(ePrint);
                            }
                         }
                         else{
                            printf(RED"No Employees\n"RESET);
                         }
                         halt_untilESC();
                         initial_state(PRINT_OPTION);
                    break;
                     default:
                        ;
               }
                break;
            default:
            ;

            }
        }
    }


}


int main()
{
    myMenu();
    return 0;
}
