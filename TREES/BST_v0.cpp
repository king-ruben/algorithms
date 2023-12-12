#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST_tree {
private:
    Node* root;

    // Helper function for inserting a value into the tree
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function for finding the minimum value node in a tree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function for deleting a value from the tree
    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* temp = findMin(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = remove(node->right, temp->data);
        }

        return node;
    }

    // Helper function for searching a value in the tree
    bool contains(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

public:
    BST_tree() : root(nullptr) {}

    // Function to insert a value into the tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to delete a value from the tree
    void remove(int value) {
        root = remove(root, value);
    }

    // Function to check if a value is present in the tree
    bool contains(int value) {
        return contains(root, value);
    }
};

int main() {
    BST_tree bst;

    // Inserting values into the binary search tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Checking if certain values are present in the tree
    std::cout << "Tree contains 20: " << (bst.contains(20) ? "Yes" : "No") << std::endl;
    std::cout << "Tree contains 90: " << (bst.contains(90) ? "Yes" : "No") << std::endl;

    // Removing a value from the tree
    bst.remove(30);

    // Checking again after removal
    std::cout << "Tree contains 30: " << (bst.contains(30) ? "Yes" : "No") << std::endl;

    return 0;
}
