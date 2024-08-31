#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    std::string name;
    int age;
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    int getAge() const {
        return age;
    }

    void displayPerson() const {
        std::cout << "Name: " << name << ", Age: " << age << "\n";
    }

    
    Person* findEldest(Person* other) {
        if (this->age >= other->age) {
            return this;
        } else {
            return other;
        }
    }
};

int main() {
    std::vector<Person> persons;
    persons.push_back(Person("Alice", 30));
    persons.push_back(Person("Bob", 40));
    persons.push_back(Person("Charlie", 35));
    persons.push_back(Person("David", 50));
    persons.push_back(Person("Eva", 45));

    if (persons.empty()) {
        std::cout << "No persons in the list.\n";
        return 1;
    }

    																							
    Person* eldest = &persons[0];

    for (size_t i = 1; i < persons.size(); ++i) {
        eldest = eldest->findEldest(&persons[i]);
    }

    std::cout << "The eldest person is:\n";
    eldest->displayPerson();

    return 0;
}

