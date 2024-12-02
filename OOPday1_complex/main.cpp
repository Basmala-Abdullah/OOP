#include <iostream>
#include <cmath>


using namespace std;

class Complex{
    float real;
    float img;

public:
    Complex() {
        this->real=0;
        this->img=0;
    }


    void setImg(float i){
      this->img = i;
    }

    float getImg(){
        return this->img;
    }

    void setReal(float r){
        this->real = r;
    }

    float getReal(){
        return this->real;
    }

    void addComplex(Complex c){
        this->real+=c.real;
        this->img+=c.img;
    }

    void subtractComplex(Complex c){
        this->real-= c.real;
        this->img-=c.img;
    }

    void print(){
        cout<<this->real<<" + "<<this->img<<"i"<<endl;
    }

};

Complex add(Complex c1, Complex c2){
    Complex result;
    result.addComplex(c1);
    result.addComplex(c2);
    return result;
}

Complex subtract(Complex c1, Complex c2){
    Complex result;
    result.addComplex(c1);
    result.subtractComplex(c2);
    return result;
}


void swapByValue(int a,int b) {
    int temp=a;
    a=b;
    b=temp;
}

void swapByAddress(int* a,int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swapByReference(int& a,int& b) {
    int temp=a;
    a=b;
    b=temp;
}

int validateNumber(){
    if (cin.fail()) {
            cout << "Error: Invalid input, enter numeric values only." << endl;
            return 0;
    }
    return 1;
}


int main() {
    Complex myComp1;
    Complex myComp2;
    Complex resultComp;

    float real1, img1, real2, img2;
    cout<<"Enter real and imaginary parts of the first complex number:"<<endl;
    cin>>real1>>img1;

    if (!validateNumber()) {
            return 0;
    }
    myComp1.setReal(real1);
    myComp1.setImg(img1);

    cout<<"Enter real and imaginary parts of the second complex number:"<<endl;
    cin>>real2>>img2;

    if (!validateNumber()) {
            return 0;
    }
    myComp2.setReal(real2);
    myComp2.setImg(img2);

    cout<<"First complex number:"<<endl;
    myComp1.print();
    cout<<"Second complex number:"<<endl;
    myComp2.print();

    resultComp=add(myComp1,myComp2);
    cout<<"\nSum: ";
    resultComp.print();


    resultComp = subtract(myComp1, myComp2);
    cout << "\nDifference (first complex - second complex): ";
    resultComp.print();

    ///////////////////////////////////testing swap functions//////////////////////////
    int a = 4, b = 6;

    //by value
    cout << "\nBefore swap by value: a = " <<a<<", b = "<<b<<endl;
    swapByValue(a,b);
    cout<<"After swap by value: a = "<<a<<", b = "<<b<<"  --> No change"<< endl;

    //by address
    cout << "\nBefore swap by address: a = "<<a<<",b = "<<b<<endl;
    swapByAddress(&a, &b);
    cout << "After swap by address: a = "<<a<<", b = "<<b<<endl;

    //by reference
    cout<<"\nBefore swap by reference: a = "<<a<<", b = "<<b<<endl;
    swapByReference(a, b);
    cout<<"After swap by reference: a = "<<a<<", b = "<<b<<endl;


    return 0;
}
