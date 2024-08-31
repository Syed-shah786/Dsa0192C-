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

    
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << value << " enqueued to the queue.\n";
    }

    
    void dequeue() {
        if (front == NULL) {
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

    
    int peek() {
        if (front == NULL) {
            std::cout << "Queue is empty.\n";
            return -1; 
        }
        return front->data;
    }

    
    void display() {
        if (front == NULL) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    std::cout << "Contents of the queue: ";
    queue.display();

    queue.dequeue();
    queue.dequeue();

    std::cout << "Contents of the queue after dequeuing: ";
    queue.display();

    return 0;
}

