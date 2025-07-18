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
    void TraverseLeft(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);
        if (root->left)
            TraverseLeft(root->left, ans);
        else
            TraverseLeft(root->right, ans);
    }

    void TraverseLeaf(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

        TraverseLeaf(root->left, ans);
        TraverseLeaf(root->right, ans);
    }

    void TraverseRight(Node* root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
            TraverseRight(root->right, ans);
        else
            TraverseRight(root->left, ans);

        // Push after recursion to reverse the order
        ans.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        ans.push_back(root->data); // root

        // 1. Left boundary (excluding leaf)
        TraverseLeft(root->left, ans);

        // 2. Leaf nodes (left and right subtree)
        TraverseLeaf(root->left, ans);
        TraverseLeaf(root->right, ans);

        // 3. Right boundary (excluding leaf)
        TraverseRight(root->right, ans);

        return ans;
    }
};
