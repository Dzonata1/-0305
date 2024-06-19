#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

 
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

   
    Fraction() : numerator(0), denominator(1) {}

    
    void display() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    
    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const Fraction& other) const {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator*(const Fraction& other) const {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

   
    Fraction operator+(int integer) const {
        return *this + Fraction(integer, 1);
    }

    Fraction operator-(int integer) const {
        return *this - Fraction(integer, 1);
    }

    Fraction operator*(int integer) const {
        return *this * Fraction(integer, 1);
    }

    
    Fraction& operator+=(const Fraction& other) {
        *this = *this + other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        *this = *this - other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        *this = *this * other;
        return *this;
    }

    
    Fraction& operator+=(int integer) {
        *this = *this + integer;
        return *this;
    }

    Fraction& operator-=(int integer) {
        *this = *this - integer;
        return *this;
    }

    Fraction& operator*=(int integer) {
        *this = *this * integer;
        return *this;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    Fraction f3 = f1 + f2;
    f3.display(); // 5/4

    Fraction f4 = f1 - f2;
    f4.display(); // -1/4

    Fraction f5 = f1 * f2;
    f5.display(); // 3/8

    Fraction f6 = f1 + 2;
    f6.display(); // 5/2

    Fraction f7 = f1 - 2;
    f7.display(); // -3/2

    Fraction f8 = f1 * 2;
    f8.display(); // 1

    return 0;
}

      


