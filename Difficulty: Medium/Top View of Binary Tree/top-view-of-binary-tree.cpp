/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int>m;
        q.push({root,0});
        
        while(!q.empty()){
            Node* curr=q.front().first;
            int horizondis=q.front().second;
            q.pop();
            
            if(m.find(horizondis)==m.end()){
                m[horizondis]=curr->data;
            }
            
            if(curr->left){
                q.push({curr->left,horizondis-1});
            }
            if(curr->right){
                q.push({curr->right,horizondis+1});
            }
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};