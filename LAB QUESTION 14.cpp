#include <iostream>
#include <cstring> 

using namespace std;

class MyString {
private:
    char* buffer;

public:
    
    MyString(const char* initialInput) {
        if (initialInput != NULL) {
            buffer = new char[strlen(initialInput) + 1];
            strcpy(buffer, initialInput);
        } else {
            buffer = NULL;
        }
        cout << "Constructor called: " << buffer << endl;
    }

    
    MyString(const MyString& copySource) {
        if (copySource.buffer != NULL) {
            buffer = new char[strlen(copySource.buffer) + 1];
            strcpy(buffer, copySource.buffer);
        } else {
            buffer = NULL;
        }
        cout << "Copy Constructor called: " << buffer << endl;
    }

    
    MyString& operator=(const MyString& copySource) {
        if (this == &copySource) {
            return *this;
        }
        delete[] buffer;
        if (copySource.buffer != NULL) {
            buffer = new char[strlen(copySource.buffer) + 1];
            strcpy(buffer, copySource.buffer);
        } else {
            buffer = NULL;
        }
        cout << "Overloaded Assignment Operator called: " << buffer << endl;
        return *this;
    }

    
    void display() const {
        cout << "Buffer content: " << buffer << endl;
    }

    
    ~MyString() {
        cout << "Destructor called: " << buffer << endl;
        delete[] buffer;
    }
};

int main() {
    
    cout << "Using Constructor:" << endl;
    MyString str1("Hello");

    
    cout << "\nUsing Copy Constructor:" << endl;
    MyString str2 = str1;

    
    cout << "\nUsing Overloaded Assignment Operator:" << endl;
    MyString str3("World");
    str3 = str2;

    
    cout << "\nDisplaying str1:" << endl;
    str1.display();
    cout << "\nDisplaying str2:" << endl;
    str2.display();
    cout << "\nDisplaying str3:" << endl;
    str3.display();

    return 0;
}

