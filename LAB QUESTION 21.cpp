#include <iostream>
#include <string>
#include <sstream>

int main() {
    // String to integer conversion
    std::string strNum = "12345";
    int intNum;
    std::stringstream ss;

    ss << strNum;
    ss >> intNum;

    if (ss.fail()) {
        std::cout << "Conversion failed\n";
    } else {
        std::cout << "String to integer conversion: " << strNum << " -> " << intNum << "\n";
    }

    // Clear the stringstream for reuse
    ss.clear();
    ss.str("");

    // Integer to string conversion
    intNum = 67890;
    ss << intNum;
    strNum = ss.str();

    std::cout << "Integer to string conversion: " << intNum << " -> " << strNum << "\n";

    return 0;
}

