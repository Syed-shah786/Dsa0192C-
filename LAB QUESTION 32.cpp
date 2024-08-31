#include <iostream>
#define MAX_SIZE 5 // Define the maximum size of the circular queue

class CircularQueue {
private:
    int front;
    int rear;
    int size;
    int* queue;

public:
    CircularQueue(int s = MAX_SIZE) : front(-1), rear(-1), size(s) {
        queue = new int[size];
    }

    // Check if the queue is full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        queue[rear] = value;
        std::cout << value << " enqueued to the queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        std::cout << queue[front] << " dequeued from the queue.\n";
        
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % size;
        }
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return -1; // Return a sentinel value indicating an error
        }

        return queue[front];
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        while (true) {
            std::cout << queue[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % size;
        }
        std::cout << "\n";
    }

    // Destructor to clean up memory
    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50); 

    std::cout << "Front element: " << cq.getFront() << "\n";

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60); 
    cq.display();

    return 0;
}

