#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;


class MyException : public exception {
public:
    virtual const char* what() const throw() {
        return "MyException occurred";
    }
};

class AnotherException : public exception {
public:
    virtual const char* what() const throw() {
        return "AnotherException occurred";
    }
};

int main() {
    try {
        int choice;
        cout << "Enter a number (1, 2, or 3): ";
        cin >> choice;

        if (choice == 1) {
            throw MyException();
        } else if (choice == 2) {
            throw AnotherException();
        } else if (choice == 3) {
            throw runtime_error("Standard runtime_error occurred");
        } else {
            throw logic_error("Standard logic_error occurred");
        }

    } catch (const MyException& e) {
        cout << "Caught MyException: " << e.what() << endl;
    } catch (const AnotherException& e) {
        cout << "Caught AnotherException: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Caught runtime_error: " << e.what() << endl;
    } catch (const logic_error& e) {
        cout << "Caught logic_error: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Caught a general exception: " << e.what() << endl;
    }

    return 0;
}

