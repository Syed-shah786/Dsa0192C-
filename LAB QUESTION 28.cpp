#include <iostream>
#include <fstream>
#include <string>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee(const char* filename, const Employee& employee) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
    outFile.close();
}

void displayAllEmployees(const char* filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    
    Employee employee;
    while (inFile.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        std::cout << "ID: " << employee.id << "\n";
        std::cout << "Name: " << employee.name << "\n";
        std::cout << "Salary: " << employee.salary << "\n";
        std::cout << "-----------------------\n";
    }
    inFile.close();
}

void searchEmployeeByID(const char* filename, int id) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    
    Employee employee;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        if (employee.id == id) {
            std::cout << "ID: " << employee.id << "\n";
            std::cout << "Name: " << employee.name << "\n";
            std::cout << "Salary: " << employee.salary << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Employee with ID " << id << " not found.\n";
    }
    inFile.close();
}

int main() {
    const char* filename = "employees.dat";
    int choice;
    Employee employee;
    int searchID;

    while (true) {
        std::cout << "1. Add Employee\n";
        std::cout << "2. Display All Employees\n";
        std::cout << "3. Search Employee by ID\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter ID: ";
                std::cin >> employee.id;
                std::cin.ignore(); 
                std::cout << "Enter Name: ";
                std::cin.getline(employee.name, 50);
                std::cout << "Enter Salary: ";
                std::cin >> employee.salary;
                addEmployee(filename, employee);
                break;
            case 2:
                displayAllEmployees(filename);
                break;
            case 3:
                std::cout << "Enter ID to search: ";
                std::cin >> searchID;
                searchEmployeeByID(filename, searchID);
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

