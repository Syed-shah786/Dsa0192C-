  #include <iostream>
#include <vector>

class Vector {
private:
    std::vector<double> elements;

public:
    
    Vector(int size, double value = 0.0) : elements(size, value) {}

    
    friend std::istream& operator>>(std::istream& in, Vector& v);

    
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);

    
    friend Vector operator*(const Vector& v, double scalar);
    friend Vector operator*(double scalar, const Vector& v);

    
    int size() const {
        return elements.size();
    }

    
    double& operator[](int index) {
        return elements[index];
    }
    const double& operator[](int index) const {
        return elements[index];
    }
};


std::istream& operator>>(std::istream& in, Vector& v) {
    for (int i = 0; i < v.size(); ++i) {
        in >> v[i];
    }
    return in;
}


std::ostream& operator<<(std::ostream& out, const Vector& v) {
    for (int i = 0; i < v.size(); ++i) {
        out << v[i] << " ";
    }
    return out;
}


Vector operator*(const Vector& v, double scalar) {
    Vector result(v.size());
    for (int i = 0; i < v.size(); ++i) {
        result[i] = v[i] * scalar;
    }
    return result;
}

Vector operator*(double scalar, const Vector& v) {
    return v * scalar;  
}

int main() {
    
    Vector v(3);

    
    std::cout << "Enter 3 elements for the vector: ";
    std::cin >> v;

    
    std::cout << "Vector: " << v << std::endl;

    
    Vector result = v * 2.0;

    
    std::cout << "Vector multiplied by 2: " << result << std::endl;

    return 0;
}

