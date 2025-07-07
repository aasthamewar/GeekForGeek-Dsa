
class Solution {
public:
    bool isSubset(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (n == 0) return false;

        if (dp[n][sum] != -1) return dp[n][sum];

        if (arr[n - 1] > sum)
            return dp[n][sum] = isSubset(arr, n - 1, sum, dp);

        return dp[n][sum] = isSubset(arr, n - 1, sum, dp) ||
                            isSubset(arr, n - 1, sum - arr[n - 1], dp);
    }

    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if (sum % 2 != 0)
            return false;

        sum /= 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return isSubset(arr, n, sum, dp);
    }
};
