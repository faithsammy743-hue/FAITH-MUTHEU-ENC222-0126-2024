#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

 Fraction& largest(Fraction& x, Fraction& y, Fraction& z) {
    Fraction* best = &x;

    if (1LL * y.numerator * best->denominator > 1LL * best->numerator * y.denominator) {
        best = &y;
    }
    if (1LL * z.numerator * best->denominator > 1LL * best->numerator * z.denominator) {
        best = &z;
    }

    return *best; // return-by-reference
}

int main() {
    Fraction fx{1, 2};  
    Fraction fy{3, 4};  
    Fraction fz{5, 6};  

    Fraction& best = largest(fx, fy, fz);

    cout << "Largest: " << best.numerator << "/" << best.denominator << "\n";
    return 0;
}    

