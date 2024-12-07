#include <iostream>

using namespace std;

class Base{
private:
    int a;
public:
    Base(){}
    Base(int a){
        this->a=a;
    }

    int sum(){
        return a;

    }

    int getA(){
        return a;

    }




};

class Derived: public Base{
private:
    int b,c;
public:
    Derived(){
    }

    Derived(int a,int b,int c):Base(a){
        this->b=b;
        this->c=c;
    }
    int sum(){
        return (Base::sum()+b+c);
    }


};

class SecondDerived: public Derived{
private:
    int d;
public:
    SecondDerived(){
    }
    SecondDerived(int a,int b,int c,int d):Derived(a,b,c){
        this->d=d;
    }

    int sum(){
        return (Derived::sum()+d);
    }
};

int returnA(Base b){
    return b.getA();
}

int main()
{

    Base baseObj(10);
    cout<<"Base sum: "<<baseObj.sum()<< endl; //10

    Derived derivedObj(11,20,30);
    cout<<"Derived sum: "<<derivedObj.sum()<<endl; //11+20+30= 61

    SecondDerived secondDerivedObj(12,22,32,40);
    cout<<"SecondDerived sum: "<<secondDerivedObj.sum()<<endl; //12+22+32+40=106

/////////////////////////////////////////////////////////////////////////////////

    cout<<"\nTesting Polymorphism effect"<<endl;

    cout<<"returnA(baseObj): "<<returnA(baseObj)<<endl; //10

    cout<<"returnA(derivedObj): "<<returnA(derivedObj)<<endl; //11

    cout<<"returnA(secondDerivedObj): "<<returnA(secondDerivedObj)<<endl; //12


    return 0;
}
