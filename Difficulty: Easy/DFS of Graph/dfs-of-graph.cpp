class Solution {
  public:
  void check(vector<vector<int>>& adj, vector<int>& ans, int index, vector<bool>& vis){
      if(vis[index]){
          return;
      }
      vis[index]=true;
      ans.push_back(index);
      for(int v: adj[index]){
          if(!vis[v]){
            //   vis[v]=true;
              check(adj,ans,v,vis);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>vis(n,false);
        //vis[0]=true;
        vector<int>ans;
        check(adj,ans,0,vis);
        return ans;
    }
};