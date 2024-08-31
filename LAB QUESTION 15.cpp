#include <iostream>
using namespace std;


class alpha {
public:
    alpha() {
        cout << "Constructor of alpha called" << endl;
    }
};


class beta {
public:
    beta() {
        cout << "Constructor of beta called" << endl;
    }
};


class gamma : public alpha, public beta {
public:
    gamma() {
        cout << "Constructor of gamma called" << endl;
    }
};

int main() {
    cout << "Creating object of class gamma:" << endl;
    gamma obj;

    return 0;
}

