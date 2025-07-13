/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        int left1=maxDepth(root->left);
        int right1=maxDepth(root->right);
        return 1+max(left1,right1);
    }
};
