class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        // in this question we will use bfs method
        
        int n=mat.size();
        int m=mat[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int ans=0;
        //bfs logic here
        while(q.size()>0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            
            if(i-1>=0 && !vis[i-1][j] && mat[i-1][j]==1){
                q.push({{i-1,j},time+1});
                vis[i-1][j]=true;
            }
            if(j-1>=0 && !vis[i][j-1] && mat[i][j-1]==1){
                q.push({{i,j-1},time+1});
                vis[i][j-1]=true;
            }
            if(i+1<n && !vis[i+1][j] && mat[i+1][j]==1){
                q.push({{i+1,j},time+1});
                vis[i+1][j]=true;
            }
            if(j+1<m && !vis[i][j+1] && mat[i][j+1]==1){
                q.push({{i,j+1},time+1});
                vis[i][j+1]=true;
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};