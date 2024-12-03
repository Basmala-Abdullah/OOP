#include "neededFunctions.h"

void forColoringText(){
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error getting console handle\n");
        return;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        fprintf(stderr, "Error getting console mode\n");
        return;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) {
        fprintf(stderr, "Error setting console mode\n");
        return;
    }
}



int cinValidNumber(){
    if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid input, enter numeric values only." << endl;
            return 0;
    }
    return 1;
}


int cin_isPositiveNumInput(int input){
    if(!(cinValidNumber())){

        return 0;
    }else if(input<=0){
        cout << "Error: Invalid input, enter positive numeric values only." << endl;
        return 0;
    }
    return 1;
}
void halt_untilESC(){
    char ch;
    while(ch != 27){
        ch=getch();
    }
}

int is_numeric(const char *str) {
    if (str == NULL || *str == '\0') return 0; // Null or empty string check

    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Non-numeric character found
        }
        str++;
    }
    return 1; // All characters are numeric
}

int contains_only_characters(char *str) {
    if (str == NULL) return 0; // Null check

    while (*str) {
        if (!(isalpha(*str)|| *str == ' ')) {
            return 0; //non-alphabetic character found
        }
        str++;
    }
    return 1; //all characters are alphabetic
}


