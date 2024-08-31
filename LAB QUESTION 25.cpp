#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputString;

    // Input a string
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    // Calculate the length of the string
    std::cout << "Length of the string: " << inputString.length() << "\n";

    // Store the string in a file
    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }
    outFile << inputString;
    outFile.close();

    // Fetch the stored characters from the file
    std::ifstream inFile("output.txt");
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }
    std::string fetchedString;
    std::getline(inFile, fetchedString);
    inFile.close();

    // Display the fetched string
    std::cout << "Fetched string from the file: " << fetchedString << "\n";

    return 0;
}

