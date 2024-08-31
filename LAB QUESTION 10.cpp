#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    
    void display() const {
        std::cout << real << " + " << imag << "i";
    }
};

int main() {
    
    Complex c1(3.0, 2.0);
    Complex c2(1.0, 4.0);

    
    Complex sum = c1 + c2;

    
    Complex product = c1 * c2;

    
    std::cout << "First complex number: ";
    c1.display();
    std::cout << std::endl;

    std::cout << "Second complex number: ";
    c2.display();
    std::cout << std::endl;

    std::cout << "Sum of the two complex numbers: ";
    sum.display();
    std::cout << std::endl;

    std::cout << "Product of the two complex numbers: ";
    product.display();
    std::cout << std::endl;

    return 0;
}

