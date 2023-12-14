#include <iostream>
#include <queue>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}

};

void bfs(TreeNode* root)
{
    if(!root) return;
    std::queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){ // while there are elements in q
     TreeNode* current = q.front();
     q.pop();

     std::cout << current->data << " ";
     
     if(current->left){
         q.push(current->left);
     }

     if(current->right){
         q.push(current->right);

     }
    }
}


int main(void)
{
    std::cout << "BFS algorithm example" << '\n';

    return 0;
}



/**
 * Pseudocode:
 * 
 * procedure BFS(G, root) is
 2      let Q be a queue
 3      label root as explored
 4      Q.enqueue(root)
 5      while Q is not empty do
 6          v := Q.dequeue()
 7          if v is the goal then
 8              return v
 9          for all edges from v to w in G.adjacentEdges(v) do
10              if w is not labeled as explored then
11                  label w as explored
12                  w.parent := v
13                  Q.enqueue(w)