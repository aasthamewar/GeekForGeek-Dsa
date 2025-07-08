class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9 + 7;

        // Initialize DP table
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: there's 1 subset (empty subset) with sum 0
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int sum = 0; sum <= target; sum++) {
                // Exclude the current element
                dp[i][sum] = dp[i - 1][sum];

                // Include it if possible
                if(arr[i - 1] <= sum)
                    dp[i][sum] = (dp[i][sum] + dp[i - 1][sum - arr[i - 1]]) % mod;
            }
        }

        return dp[n][target];
    }
};
