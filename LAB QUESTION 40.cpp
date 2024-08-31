#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>

using namespace std;


template<typename T>
void sortArray(T arr[], int size) {
    
    std::sort(arr, arr + size);
}


class Date {
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    
    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.day << '/' << date.month << '/' << date.year;
        return os;
    }

private:
    int day, month, year;
}; 


class String {
public:
    String(const char* s) : str(s) {}

    
    bool operator<(const String& other) const {
        return str < other.str;
    }

    
    friend ostream& operator<<(ostream& os, const String& s) {
        os << s.str;
        return os;
    }

private:
    std::string str;
}; 

int main() {
    
    int intArr[] = { 5, 2, 9, 1, 5, 6 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    sortArray(intArr, intSize);
    cout << "Sorted integers: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    
    Date dateArr[] = { Date(12, 5, 2022), Date(3, 4, 2021), Date(7, 7, 2023) };
    int dateSize = sizeof(dateArr) / sizeof(dateArr[0]);
    sortArray(dateArr, dateSize);
    cout << "Sorted dates: ";
    for (int i = 0; i < dateSize; ++i) {
        cout << dateArr[i] << " ";
    }
    cout << endl;

    
    String strArr[] = { String("banana"), String("apple"), String("cherry") };
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    sortArray(strArr, strSize);
    cout << "Sorted strings: ";
    for (int i = 0; i < strSize; ++i) {
        cout << strArr[i] << " ";
    }
    cout << endl;

    return 0;
}

