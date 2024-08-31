#include <iostream>
#include <fstream>
#include <string>

void readFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile.c_str()); // Convert std::string to const char*
    if (!inFile) {
        std::cerr << "Error opening input file: " << inputFile << "\n";
        return;
    }

    std::ofstream outFile(outputFile.c_str()); // Convert std::string to const char*
    if (!outFile) {
        std::cerr << "Error opening output file: " << outputFile << "\n";
        inFile.close();
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        outFile << line << "\n";
    }

    std::cout << "Data successfully copied from " << inputFile
              << " to " << outputFile << "\n";

    inFile.close();
    outFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    readFile(inputFile, outputFile);

    return 0;
}

