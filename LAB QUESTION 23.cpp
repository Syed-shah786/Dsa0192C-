#include <iostream>
#include <sstream>

class ClassA; // Forward declaration

class ClassB {
private:
    std::string value;
public:
    ClassB(const std::string& val = "") : value(val) {}

    // Conversion constructor from ClassA to ClassB
    ClassB(const ClassA& obj);

    std::string getValue() const {
        return value;
    }

    void display() const {
        std::cout << "ClassB value: " << value << "\n";
    }
};

class ClassA {
private:
    int value;
public:
    ClassA(int val = 0) : value(val) {}

    int getValue() const {
        return value;
    }

    void display() const {
        std::cout << "ClassA value: " << value << "\n";
    }

    // Conversion routine to ClassB
    operator ClassB() const {
        std::stringstream ss;
        ss << value;
        return ClassB(ss.str());
    }
};

// Conversion constructor from ClassA to ClassB (implementation)
ClassB::ClassB(const ClassA& obj) {
    std::stringstream ss;
    ss << obj.getValue();
    value = ss.str();
}

int main() {
    ClassA objA(42);
    ClassB objB("123");

    objA.display();
    objB.display();

    // Converting ClassA to ClassB using conversion routine in ClassA
    ClassB objB_from_A = objA;
    objB_from_A.display();

    return 0;
}

