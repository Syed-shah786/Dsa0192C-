#include <iostream>


struct Node {
    int data;
    Node* next;
};


class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    
    bool isEmpty() {
        return front == NULL;
    }

    
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << value << " enqueued to the queue.\n";
    }

    
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        std::cout << temp->data << " dequeued from the queue.\n";
        delete temp;
    }

    
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return -1; 
        }

        return front->data;
    }

    
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.getFront() << "\n";

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}

