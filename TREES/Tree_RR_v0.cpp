#include <iostream>
#include <memory>
#include <cmath>
#include<cstdlib>

#define N 5
#define MAX 100
#define MIN 1

class Node{
    public:
        int data;
        std::unique_ptr<Node> l;
        std::unique_ptr<Node> r;

        Node(int value) : data(value), l(nullptr), r(nullptr) {}
};

int range = (MAX - MIN) + 1;

void insert(std::unique_ptr<Node> &root, int value);
void inOrderTraversal(const Node* root);
void preOrderTraversal(const Node* root);


int main(int argc, const char* argv[]){
    std::cout << "Welcome" << '\n';
    std::unique_ptr<Node> root = nullptr;

    std::srand( (unsigned)time(NULL) );
    // for(auto i = -N; i < N; i++)
    // insert( root, pow(i, i) );
    for(auto i = 0; i < N; i++)
     insert(root, rand() % range + MIN);

    std::cout << "######## IN-ORDER TRAVERSAL ########" << '\n';
    inOrderTraversal(root.get());
    std::cout << "######## PRE-ORDER TRAVERSAL ########" << '\n';
    preOrderTraversal(root.get());
    return 0;
}


void insert(std::unique_ptr<Node> &root, int value){

    if(!root){ // if(root != nullptr)
        root = std::make_unique<Node>(value);
    }else if(value < root->data){
        insert(root->l, value);
    }else // value > root->data
        insert(root->r, value);
    
}

void inOrderTraversal(const Node* root){

    
    if(root){ //  if(root != nullptr)
     inOrderTraversal(root->l.get());
     std::cout << root->data << '\n';
     inOrderTraversal(root->r.get());
    }
}

void preOrderTraversal(const Node* root){

    if(!root) return;

    std::cout << root->data << '\n';
    preOrderTraversal(root->l.get());
    preOrderTraversal(root->r.get());
}
