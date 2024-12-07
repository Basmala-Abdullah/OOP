#include <iostream>
#include <graphics.h>

using namespace std;

class Shape{
private:
  int color;
public:
  Shape():color(WHITE) {}
  Shape(int c):color(c) {}
  int getColor(){return color;}
};


class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Line:public Shape {
private:
    Point start;
    Point end;

public:
    Line() : start(), end(), Shape() {}
    Line(int x1, int y1, int x2, int y2, int c = WHITE) : start(x1, y1), end(x2, y2), Shape(c) {}

    void draw() {
        setcolor(getColor());
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect:public Shape {
private:
    Point ul; // Upper-left point
    Point lr; // Lower-right point

public:
    Rect() : ul(), lr(), Shape() {}
    Rect(int x1, int y1, int x2, int y2, int c = WHITE) : ul(x1, y1), lr(x2, y2), Shape(c) {}

    void draw() {
        setcolor(getColor());
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Circle:public Shape {
private:
    Point center;
    int radius;

public:
    Circle() : center(), radius(0),  Shape() {}
    Circle(int m, int n, int r, int c = WHITE) : center(m, n), radius(r), Shape(c) {}

    void draw() {
        setcolor(getColor());
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture {
private:
    int cNum, rNum, lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle* pC) {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect* pR) {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line* pL) {
        lNum = ln;
        pLines = pL;
    }

    void paint() {
        for (int i = 0; i < cNum; i++) {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++) {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++) {
            pLines[i].draw();
        }
    }
};

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);

    Picture myPic;

    Circle cArr[3] = {
        Circle(230, 250, 50, RED),
        Circle(370, 250, 50, RED),
        Circle(300, 300, 200, GREEN)
    };
    Rect rArr[1] = { Rect(200, 350, 400, 400, CYAN) };
    Line lArr[2] = {
        Line(240, 350, 240, 400, YELLOW),
        Line(280, 350, 280, 400, YELLOW)
    };

    myPic.setCircles(3, cArr);
    myPic.setRects(1, rArr);
    myPic.setLines(2, lArr);

    myPic.paint();

    getch();
    closegraph();

    return 0;
}
