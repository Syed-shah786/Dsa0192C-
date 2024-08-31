#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int> > data; 

public:
    
    Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<int>(c, 0)) {}

    
    void setElement(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = value;
        } else {
            std::cout << "Invalid position (" << r << ", " << c << ")" << std::endl;
        }
    }

    
    int getElement(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        } else {
            std::cout << "Invalid position (" << r << ", " << c << ")" << std::endl;
            return -1; 
        }
    }

    
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create a 3x3 matrix
    Matrix mat(3, 3);

    // Set elements in the matrix
    mat.setElement(0, 0, 1);
    mat.setElement(0, 1, 2);
    mat.setElement(0, 2, 3);
    mat.setElement(1, 0, 4);
    mat.setElement(1, 1, 5);
    mat.setElement(1, 2, 6);
    mat.setElement(2, 0, 7);
    mat.setElement(2, 1, 8);
    mat.setElement(2, 2, 9);

    
    std::cout << "Matrix:" << std::endl;
    mat.display();

    
    int element = mat.getElement(1, 1);
    if (element != -1) {
        std::cout << "Element at (1, 1): " << element << std::endl;
    }

    
    int invalid_element = mat.getElement(3, 3);

    return 0;
}

