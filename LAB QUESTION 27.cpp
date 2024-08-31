#include <iostream>
#include <fstream>

struct Person {
    char name[50];
    int age;
};

void writeToFile(const char* filename, const Person& person) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&person), sizeof(Person));
    outFile.close();
}

void readFromFile(const char* filename, Person& person) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    inFile.read(reinterpret_cast<char*>(&person), sizeof(Person));
    inFile.close();
}

int main() {
    Person person1 = {"John Doe", 30};
    const char* filename = "person.dat";

    // Write the object to a file
    writeToFile(filename, person1);
    std::cout << "Person written to file.\n";

    // Read the object from the file
    Person person2;
    readFromFile(filename, person2);

    // Display the read object
    std::cout << "Person read from file:\n";
    std::cout << "Name: " << person2.name << "\n";
    std::cout << "Age: " << person2.age << "\n";

    return 0;
}

