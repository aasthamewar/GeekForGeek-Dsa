class Solution {
  public:
  bool isSum(vector<int> &arr, int n, int sum, vector<vector<int>> &dp) {
        if (sum == 0) return true;
        if (n <= 0) return false;

        if (dp[n][sum] != -1) return dp[n][sum];

        if (arr[n - 1] > sum) {
            return dp[n][sum] = isSum(arr, n - 1, sum, dp);
        } else {
            return dp[n][sum] = isSum(arr, n - 1, sum, dp) ||
                                isSum(arr, n - 1, sum - arr[n - 1], dp);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return isSum(arr, n, sum, dp);
    }
};