// User function template for C++
class Solution {
  public:
  int f(int index , vector<int>&arr,vector<int>&dp){
      if(index==0)return arr[index];
      if(index<0)return 0;
      if(dp[index]!=-1)return dp[index];
      int pick=arr[index]+f(index-2,arr,dp);
      int notpick=0+f(index-1,arr,dp);
      return dp[index] =max(pick,notpick);
  }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr, int n) {
        // code here
        vector<int> dp(n,-1);
        return f(n-1,arr,dp);
    }
};