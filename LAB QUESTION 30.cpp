#include <iostream>
#include <vector>
#include <stdexcept> 

template<typename T>
class Stack {
private:
    std::vector<T> stackData;

public:
    
    void push(const T& value) {
        stackData.push_back(value);
    }

    
    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty. Cannot pop.");
        }
        T topElement = stackData.back();
        stackData.pop_back();
        return topElement;
    }

    
    bool isEmpty() const {
        return stackData.empty();
    }

    
    size_t size() const {
        return stackData.size();
    }
};

int main() {
    
    Stack<int> intStack;

    
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    
    while (!intStack.isEmpty()) {
        std::cout << "Popped: " << intStack.pop() << "\n";
    }

    return 0;
}

