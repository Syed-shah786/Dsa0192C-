#include <iostream>
#include <stdexcept> 
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions must be the same for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix A(2, 3);
    Matrix B(2, 3);

    

    try {
        Matrix C = A + B; 
        Matrix D = A * B; 

        // Display results
        cout << "Matrix A:" << endl;
        A.display();
        cout << "Matrix B:" << endl;
        B.display();
        cout << "Matrix A + B:" << endl;
        C.display();
        cout << "Matrix A * B:" << endl;
        D.display();
    } catch (const std::invalid_argument& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}

