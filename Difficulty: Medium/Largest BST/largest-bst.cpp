class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBstHelper(Node* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // get values from left and right subtree
        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);

        // if current subtree is BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // otherwise not BST, return largest size so far
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node* root) {
        return largestBstHelper(root).maxSize;
    }
};
