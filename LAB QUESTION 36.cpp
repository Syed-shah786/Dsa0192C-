#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    
    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;
    
    Node* insert(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }
    
    void inorderTraversal(Node* node, vector<int>& result) const {
        if (node != NULL) {
            inorderTraversal(node->left, result);
            result.push_back(node->key);
            inorderTraversal(node->right, result);
        }
    }
    
    Node* copyTree(Node* node) const {
        if (node == NULL) {
            return NULL;
        }
        Node* newNode = new Node(node->key);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }
    
public:
    BinarySearchTree() {
        root = NULL;
    }
    
    void insert(int key) {
        root = insert(root, key);
    }
    
    vector<int> inorderTraversal() const {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    
    BinarySearchTree copy() const {
        BinarySearchTree newTree;
        newTree.root = copyTree(root);
        return newTree;
    }
    
    bool compare(const BinarySearchTree& other) const {
        return inorderTraversal() == other.inorderTraversal();
    }
};

// Example Usage
int main() {
    BinarySearchTree bst1;
    bst1.insert(50);
    bst1.insert(30);
    bst1.insert(20);
    bst1.insert(40);
    bst1.insert(70);
    bst1.insert(60);
    bst1.insert(80);

    vector<int> traversal1 = bst1.inorderTraversal();
    cout << "Inorder traversal of the original tree: ";
    for (size_t i = 0; i < traversal1.size(); ++i) {
        cout << traversal1[i] << " ";
    }
    cout << endl;

    BinarySearchTree bst2 = bst1.copy();
    vector<int> traversal2 = bst2.inorderTraversal();
    cout << "Inorder traversal of the copied tree: ";
    for (size_t i = 0; i < traversal2.size(); ++i) {
        cout << traversal2[i] << " ";
    }
    cout << endl;

    cout << "Are the two trees identical? " << (bst1.compare(bst2) ? "Yes" : "No") << endl;

    bst2.insert(90);
    vector<int> traversal3 = bst2.inorderTraversal();
    cout << "Inorder traversal of the modified copied tree: ";
    for (size_t i = 0; i < traversal3.size(); ++i) {
        cout << traversal3[i] << " ";
    }
    cout << endl;

    cout << "Are the two trees identical after modification? " << (bst1.compare(bst2) ? "Yes" : "No") << endl;

    return 0;
}

