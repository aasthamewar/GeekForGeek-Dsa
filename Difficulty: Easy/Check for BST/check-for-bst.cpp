class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool check(Node* root,int l,int r){
        if(!root){
            return true;
        }
        if(root->data<=l || root->data>=r){
            return false;
        }
        
        bool lh=check(root->left,l,root->data);
        bool rh=check(root->right,root->data,r);
        
        return lh&&rh;
    }
    bool isBST(Node* root) {
        // Your code here
        return check(root,-1e9,1e9);
    }
};