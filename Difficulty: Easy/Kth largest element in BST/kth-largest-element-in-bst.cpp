/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
  
    void Klargest(Node* root, int &ans, int &k)
    {
        if(!root)
        return;
        
        Klargest(root->right, ans, k);
        
        k--;
        if(k == 0)
        ans = root->data;
        
        if(k <= 0)
        return;
        
        Klargest(root->left, ans, k);
    }
  
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans;
        Klargest(root, ans, k);
        return ans;
    }
};