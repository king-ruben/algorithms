#include <iostream>
#include <memory>

struct Node {
    int data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insert(std::unique_ptr<Node>& root, int value);
void inorderTraversal(const Node* root);

int main() {
    std::unique_ptr<Node> root = nullptr;

    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    inorderTraversal(root.get());

    return 0;
}

void insert(std::unique_ptr<Node>& root, int value) {
    if (root == nullptr) {
        root = std::make_unique<Node>(value);
    } else if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

void inorderTraversal(const Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left.get());
        std::cout << root->data << " ";
        inorderTraversal(root->right.get());
    }
}
