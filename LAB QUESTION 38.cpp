#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class CustomException : public exception {
public:
    virtual const char* what() const throw() {
        return "CustomException occurred";
    }
};

void functionA() {
    try {
        
        throw CustomException();
    } catch (const CustomException& e) {
        cout << "Caught in functionA: " << e.what() << endl;
        
        throw;
    }
}

void functionB() {
    try {
        functionA();
    } catch (const exception& e) {
        cout << "Caught in functionB: " << e.what() << endl;
        
        throw;
    }
}

int main() {
    try {
        functionB();
    } catch (const exception& e) {
        cout << "Caught in main: " << e.what() << endl;
    }

    return 0;
}

