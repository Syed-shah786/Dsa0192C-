#include <iostream>
using namespace std;

class MyClass {
public:
    void* operator new(size_t size) {
        cout << "Custom new operator called with size: " << size << endl;
        void* ptr = ::operator new(size);  
        return ptr;
    }

    void operator delete(void* ptr) {
        cout << "Custom delete operator called." << endl;
        ::operator delete(ptr);  
    }

    void display() {
        cout << "Inside MyClass::display()" << endl;
    }
};

int main() {
    cout << "Creating object dynamically:" << endl;
    MyClass* obj = new MyClass();
    obj->display();

    cout << "Deleting object:" << endl;
    delete obj;

    return 0;
}

