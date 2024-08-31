#include <iostream>


struct Node {
    int data;
    Node* next;
};


class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        std::cout << value << " pushed onto the stack.\n";
    }

    
    void pop() {
        if (top == NULL) {
            std::cout << "Stack is empty. Cannot pop.\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        std::cout << temp->data << " popped from the stack.\n";
        delete temp;
    }

    
    int peek() {
        if (top == NULL) {
            std::cout << "Stack is empty.\n";
            return -1; 
        }

        return top->data;
    }

    
    void display() {
        if (top == NULL) {
            std::cout << "Stack is empty.\n";
            return;
        }

        Node* temp = top;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    std::cout << "Contents of the stack: ";
    stack.display();

    stack.pop();
    stack.pop();

    std::cout << "Contents of the stack after popping: ";
    stack.display();

    return 0;
}

