/*Structure of the node of the binary tree is as
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

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int>ans1(size);
            
            for(int i=0;i<size;i++){
                Node* frontq=q.front();
                q.pop();
                
                int index = leftToRight?i:size-i-1;
                
                ans1[index] = frontq->data;
                
                if(frontq->left){
                    q.push(frontq->left);
                }
                if(frontq->right){
                    q.push(frontq->right);
                }
                
            }
            leftToRight = !leftToRight;
            
            for(auto i:ans1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};