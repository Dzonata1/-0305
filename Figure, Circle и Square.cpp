#include <iostream>
#include <cmath>

class Figure {
public:
    virtual double area() const = 0; 
    virtual ~Figure() = default; 
};

class Circle : public Figure {
public:
    Circle(double radius) : radius(radius) {}
    double area() const override {
        return M_PI * radius * radius;
    }
private:
    double radius;
};

class Square : public Figure {
public:
    Square(double side) : side(side) {}
    double area() const override {
        return side * side;
    }
private:
    double side;
};

int main() {
    Circle circ1(1);
    Square sqare1(1);
    Figure* figs[]{&circ1, &sqare1};

    std::cout << "Area of circle: " << figs[0]->area() << std::endl; 
    std::cout << "Area of square: " << figs[1]->area() << std::endl; 

    return 0;
}







   