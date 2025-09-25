class Solution {
  public:
  void dfsans(int node,vector<vector<int>>&adj, vector<int>&vis,vector<int>&res){
      vis[node]=1;
      res.push_back(node);
      
      for(int neighbor:adj[node]){
          if(!vis[neighbor]){
              dfsans(neighbor,adj,vis,res);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<int> vis(v,0);
        vector<int> res;
        
        dfsans(0,adj,vis,res);
        return res;
        
    }
};