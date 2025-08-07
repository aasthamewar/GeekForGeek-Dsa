/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root==NULL || root==n1 || root==n2){
            return root;
        }
        Node* left = LCA(root->left,n1,n2);
        Node* right = LCA(root->right,n1,n2);
        
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
};