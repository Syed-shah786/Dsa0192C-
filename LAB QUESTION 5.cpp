 #include <iostream>
using namespace std;

class class_2; 

class class_1 {
    int data1;
public:
    void setData(int value) {
        data1 = value;
    }
    void showData() const {
        cout << "class_1 data: " << data1 << endl;
    }
    friend void swapData(class_1 &obj1, class_2 &obj2);
};

class class_2 {
    int data2;
public:
    void setData(int value) {
        data2 = value;
    }
    void showData() const {
        cout << "class_2 data: " << data2 << endl;
    }
    friend void swapData(class_1 &obj1, class_2 &obj2);
};

void swapData(class_1 &obj1, class_2 &obj2) {
    int temp = obj1.data1;
    obj1.data1 = obj2.data2;
    obj2.data2 = temp;
}

int main() {
    class_1 obj1;
    class_2 obj2;

    int value1, value2;

    cout << "Enter value for class_1 object: ";
    cin >> value1;
    obj1.setData(value1);

    cout << "Enter value for class_2 object: ";
    cin >> value2;
    obj2.setData(value2);

    cout << "\nBefore swapping:" << endl;
    obj1.showData();
    obj2.showData();

    swapData(obj1, obj2);

    cout << "\nAfter swapping:" << endl;
    obj1.showData();
    obj2.showData();

    return 0;
}

