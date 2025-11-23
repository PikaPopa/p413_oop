#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
};

class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(double x, double y) {
        a = x;
        b = y;
    }
    void area() {
        cout << a * b << endl;
    }
};

class Circle : public Shape {
    double r;
public:
    Circle(double x) {
        r = x;
    }
    void area() {
        cout << 3.14 * r * r << endl;
    }
};

class Triangle : public Shape {
    double a, b;
public:
    Triangle(double x, double y) {
        a = x;
        b = y;
    }
    void area() {
        cout << (a * b) / 2 << endl;
    }
};

class Trapezoid : public Shape {
    double a, b, h;
public:
    Trapezoid(double x, double y, double z) {
        a = x;
        b = y;
        h = z;
    }
    void area() {
        cout << ((a + b) * h) / 2 << endl;
    }
};

int main() {
    Shape* figures[4];

    figures[0] = new Rectangle(2, 3);
    figures[1] = new Circle(5);
    figures[2] = new Triangle(4, 6);
    figures[3] = new Trapezoid(2, 4, 3);

    for (int i = 0; i < 4; i++) {
        figures[i]->area();
    }
}