#include <iostream>
#include <cmath>


using namespace std;



class Complex{
    int real;
    int img;

public:
    Complex() {
        this->real=0;
        this->img=0;
    }

    Complex(int real, int img) {
        this->real=real;
        this->img=img;
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

    Complex addComplex(Complex c){
        this->real+=c.real;
        this->img+=c.img;
        return *this;
    }

    Complex subtractComplex(Complex c){
        this->real-= c.real;
        this->img-=c.img;

        return *this;
    }

    void print(){
        cout<<this->real<<" + "<<this->img<<"i"<<endl;
    }

    void setComplex(int real, int img){
        this->real = real;
        this->img = img;
    }

    Complex operator+(Complex c){
        Complex result;
        result.real = this->real + c.real;
        result.img = this->img + c.img;

        return result;
    }

    Complex operator-(Complex c){
        Complex result;
        result.real = this->real - c.real;
        result.img = this->img - c.img;
        return result;
    }

    Complex operator+(int value){
        Complex result;
        result.real = this->real + value;
        result.img =this->img + value;
        return result;
    }

    Complex operator-(int value){
        Complex result;
        result.real = this->real - value;
        result.img = this->img - value;
        return result;
    }

    int operator ==(Complex c){

        int areEqual=0;
        if((this->real == c.real) && (this->img == c.img)){
            areEqual=1;
        }
        return areEqual;
    }

    void operator +=(Complex c){

        this->real+=c.real;
        this->img+=c.img;
    }

    Complex operator++(){

        this->real++;
        this->img++;
        return *this;
    }

    Complex operator++(int extraNum){
        Complex c = *this;
        this->real++;
        this->img++;
        return c;
    }


    Complex operator--(){

        this->real--;
        this->img--;
        return *this;
    }

    Complex operator--(int extraNum){
        Complex c = *this;
        this->real--;
        this->img--;
        return c;
    }

    operator float() {
        return sqrt(real*real+img*img);
    }





    friend Complex operator+(int value, Complex c);
    friend Complex operator-(int value, Complex c);

    ~Complex(){
        //cout<<"Object is deleted"<<endl;
    }

};

Complex operator+(int value, Complex c){
    Complex result;
    result.real = c.real+value;
    result.img = c.img+value;
    return result;
}

Complex operator-(int value, Complex c){
    Complex result;
    result.real = c.real-value;
    result.img = c.img-value;
    return result;
}



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




int validateNumber(){
    if (cin.fail()) {
            cout << "Error: Invalid input, enter numeric values only." << endl;
            return 0;
    }
    return 1;
}


int main() {
    Complex c1;
    Complex c2;


    float real1, img1, real2, img2;
    cout<<"Enter real and imaginary parts of the first complex number:"<<endl;
    cin>>real1>>img1;

    if (!validateNumber()) {
            return 0;
    }
    c1.setReal(real1);
    c1.setImg(img1);

    cout<<"Enter real and imaginary parts of the second complex number:"<<endl;
    cin>>real2>>img2;

    if (!validateNumber()) {
            return 0;
    }
    c2.setReal(real2);
    c2.setImg(img2);


    Complex c3;
    c3 = c1 + c2;
    cout<<"complex c1: "; c1.print();
    cout<<"complex c2: "; c2.print();
    cout << "Magnitude of c1: " << (float)c1 << endl;
    cout<<"complex c3 = c1 + c2: ";
    c3.print();

    cout<<"complex c3 = c1 - c2: ";
    c3 = c1 - c2;
    c3.print();

    cout<<"complex c3 = c1 + 5: ";
    c3 = c1 + 5;
    c3.print();

    cout<<"complex c3 = c1 - 5: ";
    c3 = c1 - 5;
    c3.print();

    cout<<"complex c3 = 5 + c1: ";
    c3 = 5 + c1;
    c3.print();

    cout<<"complex c3 = 5 - c1: ";
    c3 = 5 - c1;
    c3.print();

    cout << "c1 == c2: " << (c1 == c2) << endl;

    cout<<"complex c1 += c2: ";
    c1 += c2;
    c1.print();

    cout<<"++c1: ";
    ++c1;
    c1.print();

    cout<<"c1++: ";
    c1++;
    c1.print();

    cout<<"--c1: ";
    --c1;
    c1.print();

    cout<<"c1--: ";
    c1--;
    c1.print();





    return 0;
}
