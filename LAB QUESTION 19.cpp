#include <iostream>

class Animal {
public:
    // Virtual function
    virtual void speak() const {
        std::cout << "Animal speaks\n";
    }

    // Virtual destructor
    virtual ~Animal() {
        std::cout << "Animal destructor called\n";
    }
};

class Dog : public Animal {
public:
    // Override the speak function
    void speak() const override {
        std::cout << "Dog barks\n";
    }

    // Destructor
    ~Dog() override {
        std::cout << "Dog destructor called\n";
    }
};

class Cat : public Animal {
public:
    // Override the speak function
    void speak() const override {
        std::cout << "Cat meows\n";
    }

    // Destructor
    ~Cat() override {
        std::cout << "Cat destructor called\n";
    }
};

void makeAnimalSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    // Create objects of Dog and Cat
    Dog dog;
    Cat cat;

    // Create pointers to the base class
    Animal* animalPtr1 = &dog;
    Animal* animalPtr2 = &cat;

    // Call the virtual function through base class pointers
    animalPtr1->speak(); // Dog barks
    animalPtr2->speak(); // Cat meows

    // Demonstrate the use of a function that takes a reference to base class
    makeAnimalSpeak(dog); // Dog barks
    makeAnimalSpeak(cat); // Cat meows

    return 0;
}

