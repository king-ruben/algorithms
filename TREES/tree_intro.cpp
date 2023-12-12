#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int value);
void inorderTraversal(Node* root);




int main(int argc, const char *argv[])
{
    Node* root = nullptr;

    root = insert(root, 30);

    insert(root, 40);
    insert(root, 50);
    insert(root, 55);
    insert(root, 99);
    insert(root, 666);

    inorderTraversal(root);

    return 0;
}

Node* insert(Node* root, int value)
{
    if(root == nullptr){
        return new Node(value);
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    }else{ // value > root->data
        root->right = insert(root->right, value);
    }
                                                                                       
    return root;
}

void inorderTraversal(Node* root)
{
    if(root != nullptr){
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
    
}