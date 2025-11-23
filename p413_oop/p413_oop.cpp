#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class Circle {
protected:
    double radius;
public:
    Circle(double r = 0) : radius(r) {}
    double getRadius() const { 
        return radius; 
    }

    void setRadius(double r) {
        radius = r; }

    double getArea() const { 

        return M_PI * radius * radius; 
    }
};

class Square {
protected:
    double side;
public:
    Square(double s = 0) : side(s) {}
    double getSide() const { 
        return side; 
    }
    void setSide(double s) { 
        side = s; 
    }
    double getArea() const { 
        return side * side; 
    }
};

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(double squareSide = 0) {
        setSide(squareSide);
        setRadius(squareSide / 2);
    }

    void setFromSquareSide(double squareSide) {
        setSide(squareSide);
        setRadius(squareSide / 2);
    }

    void setFromCircleRadius(double circleRadius) {
        setRadius(circleRadius);
        setSide(circleRadius * 2);
    }

    void printInfo() const {
        std::cout << "Square side: " << getSide() << std::endl;
        std::cout << "Circle radius:" << getRadius() << std::endl;
        std::cout << "Square area: " << Square::getArea() << std::endl;
        std::cout << "Circle area: " << Circle::getArea() << std::endl;
    }
};

int main() {
    CircleInSquare shape(10.0);
    shape.printInfo();

    shape.setFromCircleRadius(3.0);
    shape.printInfo();
}