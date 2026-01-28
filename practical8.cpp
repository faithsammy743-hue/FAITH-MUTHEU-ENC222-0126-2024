#include <iostream>
using namespace std;

// Base class
class Square {
protected:
    double side;

public:
    // Constructor
    Square(double s = 0) : side(s) {
        cout << "Square constructor called" << endl;
    }

    // Virtual destructor
    virtual ~Square() {
        cout << "Square destructor called" << endl;
    }

    double getPeri() {
        return 4 * side;
    }

    virtual double getArea() {
        return side * side;
    }
};

// Derived class
class Cube : public Square {
public:
    Cube(double s = 0) : Square(s) {
        cout << "Cube constructor called" << endl;
    }

    ~Cube() {
        cout << "Cube destructor called" << endl;
    }

    double getArea() override {
        return 6 * side * side;
    }

    double getVolume() {
        return side * side * side;
    }
};

int main() {
    Square sq(4);
    cout << "Square Perimeter: " << sq.getPeri() << endl;
    cout << "Square Area: " << sq.getArea() << endl;

    cout << endl;

    Cube cb(3);
    cout << "Cube Surface Area: " << cb.getArea() << endl;
    cout << "Cube Volume: " << cb.getVolume() << endl;

    return 0;
}
