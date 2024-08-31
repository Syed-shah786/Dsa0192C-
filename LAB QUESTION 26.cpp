#include <iostream>
#include <fstream>

int main() {
    std::string sourceFileName, destinationFileName;

    
    std::cout << "Enter the name of the source file: ";
    std::cin >> sourceFileName;
    std::cout << "Enter the name of the destination file: ";
    std::cin >> destinationFileName;

    
    std::ifstream sourceFile(sourceFileName.c_str(), std::ios::binary);
    if (!sourceFile) {
        std::cerr << "Error opening source file.\n";
        return 1;
    }

    
    std::ofstream destinationFile(destinationFileName.c_str(), std::ios::binary);
    if (!destinationFile) {
        std::cerr << "Error opening destination file.\n";
        sourceFile.close();
        return 1;
    }

    
    destinationFile << sourceFile.rdbuf();

    
    sourceFile.close();
    destinationFile.close();

    std::cout << "File copy operation completed successfully.\n";
    return 0;
}

