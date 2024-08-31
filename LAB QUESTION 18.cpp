#include <iostream>

class Base {
public:
    virtual void show() const {
        std::cout << "Base class show function called.\n";
    }

    virtual ~Base() {
        std::cout << "Base class destructor called.\n";
    }
};

class Derived : public Base {
public:
    void show() const override {
        std::cout << "Derived class show function called.\n";
    }

    ~Derived() override {
        std::cout << "Derived class destructor called.\n";
    }
};

int main() {
    // Pointer to base class object
    Base* basePtr = new Base();
    basePtr->show(); // Calls Base's show

    // Pointer to derived class object
    Base* derivedPtr = new Derived();
    derivedPtr->show(); // Calls Derived's show due to polymorphism

    // Cleaning up the dynamically allocated memory
    delete basePtr;
    delete derivedPtr;

    return 0;
}

