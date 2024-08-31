#include <iostream>

class MyClass {
private:
    int value;

public:
    
    MyClass(int v) : value(v) {
        std::cout << "Constructor called. Value initialized to " << value << std::endl;
    }

    
    ~MyClass() {
        std::cout << "Destructor called. Value was " << value << std::endl;
    }

    
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    
    MyClass* obj = new MyClass(42);

    
    obj->display();

    
    delete obj;

    return 0;
}

