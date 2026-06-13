class Solution {
  public:
  int maxiSum(vector<int>& arr, int n, vector<int>& dp){
      if(n<=0)return 0;
      if(n == 1)return arr[0];
      if(dp[n]!=-1)return dp[n];
      //take it 
      int take = arr[n-1] + maxiSum(arr,n-2,dp);
      int notTake = maxiSum(arr,n-1,dp);
      return dp[n] = max(take,notTake);
  }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return maxiSum(arr,n,dp);
        
    }
};