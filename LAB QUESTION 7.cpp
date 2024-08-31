#include <iostream>

class Example {
private:
    int value;

public:
    
    Example(int v) : value(v) {}

    
    Example(const Example& obj) {
        value = obj.value;
    }

    
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    
    Example obj1(10);
    std::cout << "Original object: ";
    obj1.display();

    
    Example obj2 = obj1;
    std::cout << "Copied object: ";
    obj2.display();

    return 0;
}

