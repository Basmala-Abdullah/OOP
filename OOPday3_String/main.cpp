#include <iostream>
#include "string_operations.h"
using namespace std;

class My_String{

    char *ptr;
    int size;
public:
    My_String(char *s){
        size = my_strLen(s);
        size++;
        ptr = new char[size];
        if(ptr!=NULL){
            int i=0;
            while(s[i] != '\0'){
                ptr[i] = s[i];
                i++;
            }
            ptr[i] = '\0';
        }
    }

    void print(){
        int i=0;
        while(this->ptr[i]!='\0'){
            cout<<ptr[i];
            i++;
        }
        cout<<endl;

    }

    int getSize(){
        return size;
    }

    My_String(My_String &s) {
        cout<<"copy called"<<endl;
        size = s.size;
        size++;
        ptr = new char[size];
        my_strcpy(ptr, s.ptr,size);
    }


    ~My_String() {
        delete[] ptr;
    }

};


int main()
{
    char input[100];
    cout<<"Enter a string: ";
    scanf("%[^\n]",input);

    My_String str1(input);
    cout<<"You entered: ";
    str1.print();

    cout<<"Length of the string = "<<str1.getSize()<<endl;




    return 0;
}
