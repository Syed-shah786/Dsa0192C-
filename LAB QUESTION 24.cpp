#include <iostream>
#include <iomanip> 

int main() {
    double number = 12345.6789;

    
    std::cout << "Default: " << number << "\n";

    
    std::cout.setf(std::ios::fixed); 
    std::cout << "Fixed-point notation: " << number << "\n";
    std::cout.unsetf(std::ios::fixed); 

    std::cout.setf(std::ios::scientific); 
    std::cout << "Scientific notation: " << number << "\n";
    std::cout.unsetf(std::ios::scientific); 

    
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed);
    std::cout << "Fixed-point with precision 2: " << number << "\n";
    std::cout.unsetf(std::ios::fixed);

    std::cout.precision(5);
    std::cout.setf(std::ios::scientific);
    std::cout << "Scientific with precision 5: " << number << "\n";
    std::cout.unsetf(std::ios::scientific);

    
    std::cout.setf(std::ios::showpoint);
    std::cout << "Showpoint: " << number << "\n";
    std::cout.unsetf(std::ios::showpoint);

    
    std::cout << std::setw(20) << std::setfill('*') << number << "\n";

    return 0;
}

