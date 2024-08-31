#include <iostream>


struct Node {
    int data;
    Node* next;
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        std::cout << value << " inserted at the beginning.\n";
    }

    
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << value << " inserted at the end.\n";
    }

    
    void deleteNode(int value) {
        if (head == NULL) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << value << " deleted from the list.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            std::cout << value << " not found in the list.\n";
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            std::cout << value << " deleted from the list.\n";
        }
    }

    
    void display() {
        if (head == NULL) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    
    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    std::cout << "Contents of the list: ";
    list.display();

    list.deleteNode(20);
    list.deleteNode(30);

    std::cout << "Contents of the list after deletion: ";
    list.display();

    return 0;
}

