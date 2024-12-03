#ifndef NEEDEDFUNCTIONS_H_INCLUDED
#define NEEDEDFUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <limits>

#include <iostream>

#define BLUE "\033[36m" //for blue text
#define RESET "\033[0m" //to reset text formatting
#define GREEN "\033[32m"
#define RED   "\033[31m"

using namespace std;

#define EXTEND_KEY -32




typedef struct Employee{

    char name[20];
     int code;
     int salary;

}Employee;


void forColoringText();
//int checkIDUniqueness(int code_toBeChecked);
//void enterNewEmployeeData();
//void deleteEmployee();
//void displayEmployees(Employee e[], int size);
//void displayIDs();
int cinValidNumber();
int cin_isPositiveNumInput(int input);

void halt_untilESC();
int is_numeric(const char *str);
int contains_only_characters(char *str);

#endif // NEEDEDFUNCTIONS_H_INCLUDED
