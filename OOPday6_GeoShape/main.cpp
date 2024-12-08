#include <iostream>

using namespace std;



class GeoShape
{
protected:
    float dim1;
    float dim2;
public:
    GeoShape()
        { dim1 = dim2 = 0; }
    GeoShape (float x)
        { dim1 = dim2 = x; }
    GeoShape (float x, float y)
    {
        dim1 = x;
        dim2 = y;
    }
    void setDim1(float x)
        { dim1 = x; }
    void setDim2(float x)
        { dim2 = x; }
    float getDim1() { return dim1; }
    float getDim2() { return dim2; }
    float calculateArea()
    {
        return 0;
    }
};

class Rect: public GeoShape
{
public:
    Rect(float x, float y): GeoShape(x, y){ }
    float calculateArea()
    {
        return dim1 * dim2;
    }
};


class Circle: private GeoShape
{

public:
    Circle(float r): GeoShape (r) { }
    void setRadius(float r) //OR we could override: setDim1()
        {dim1 = dim2 = r; }
    float getRadius()
        { return dim1; }
    //OR we could override: getDim1()
    float calculateArea()
    {
        return 22.0/7* dim1 * dim2;
    }
};


class Square: private Rect
{
public:
    Square (float x) : Rect(x, x)
    { }
    void setSquareDim (float x) //OR we could override: setDim1()
     {dim1 = dim2 = x; }
    float getSquareDim() //OR we could override: getDim1()
    { return dim1; }
    float calculateArea() //Overriding calculateArea() of Rect class.
    {
        return Rect::calculateArea();
    }
};


class Triangle: public GeoShape
{
public:
    Triangle(float b, float h): GeoShape (b, h)
    { }

    float calculateArea()
    {
        return 0.5 * dim1 * dim2;
    }
};


int main()
{

    Rect rectangle(5, 10);
    cout<<"Rectangle Area: "<<rectangle.calculateArea()<<endl;

    rectangle.setDim1(7);
    rectangle.setDim2(3);
    cout<<"Updated Rectangle Area: "<<rectangle.calculateArea()<<endl;

    Circle circle(7);
    cout<<"\nCircle Area: "<<circle.calculateArea()<<endl;
    circle.setRadius(14);
    cout<<"Updated Circle Area: "<<circle.calculateArea()<<endl;


    Square square(4);
    cout<<"\nSquare Area: "<<square.calculateArea()<<endl;

    square.setSquareDim(6);
    cout<<"Updated Square Area: "<<square.calculateArea()<<endl;

    Triangle triangle(10, 5);
    cout<<"\nTriangle Area: "<<triangle.calculateArea()<<endl;

    triangle.setDim1(8);
    triangle.setDim2(6);
    cout<<"Updated Triangle Area: "<<triangle.calculateArea()<<endl;

    return 0;
}
