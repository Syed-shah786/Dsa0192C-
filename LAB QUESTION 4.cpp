#include <iostream>
using namespace std;

class Second;  

class First {
    int number1;
public:
    void setNumber1(int n) {
        number1 = n;
    }
    friend int findMax(First, Second);
};

class Second {
    int number2;
public:
    void setNumber2(int n) {
        number2 = n;
    }
    friend int findMax(First, Second);
};

int findMax(First f, Second s) {
    if (f.number1 > s.number2)
        return f.number1;
    else
        return s.number2;
}

int main() {
    First obj1;
    Second obj2;

    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    obj1.setNumber1(num1);

    cout << "Enter the second number: ";
    cin >> num2;
    obj2.setNumber2(num2);

    int max = findMax(obj1, obj2);

    cout << "The maximum number is: " << max << endl;

    return 0;
}

