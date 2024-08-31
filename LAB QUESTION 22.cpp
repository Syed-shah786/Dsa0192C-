#include <iostream>
#include <sstream>

class ClassB; // Forward declaration

class ClassA {
private:
    int value;
public:
    ClassA(int val = 0) : value(val) {}

    // Conversion constructor from ClassB to ClassA
    ClassA(const ClassB& obj);

    int getValue() const {
        return value;
    }

    void display() const {
        std::cout << "ClassA value: " << value << "\n";
    }
};

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

// Conversion constructor from ClassB to ClassA
ClassA::ClassA(const ClassB& obj) {
    std::stringstream ss(obj.getValue());
    ss >> value;
}

// Conversion constructor from ClassA to ClassB
ClassB::ClassB(const ClassA& obj) {
    std::stringstream ss;
    ss << obj.getValue();
    ss >> value;
}

int main() {
    ClassA objA(42);
    ClassB objB("123");

    objA.display();
    objB.display();

    // Converting ClassA to ClassB
    ClassB objB_from_A = objA;
    objB_from_A.display();

    // Converting ClassB to ClassA
    ClassA objA_from_B = objB;
    objA_from_B.display();

    return 0;
}

