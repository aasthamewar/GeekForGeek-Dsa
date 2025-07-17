class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        queue<Node*> q;
        q.push(root);
        bool flag = true;  // true for left to right, false for right to left

        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                // Find position to fill node's data
                int index = (flag) ? i : (size - 1 - i);
                row[index] = node->data;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // Add current level's result to final answer
            for (int val : row) {
                ans.push_back(val);
            }

            flag = !flag;  // toggle direction
        }

        return ans;
    }
};
