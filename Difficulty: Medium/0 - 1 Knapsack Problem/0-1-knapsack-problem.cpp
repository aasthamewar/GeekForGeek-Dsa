class Solution {
public:
    int f(int W, vector<int>& val, vector<int>& wt, int n, vector<vector<int>>& dp) {
        if (n == 0 || W == 0) return 0;

        if (dp[n][W] != -1) return dp[n][W];

        int taking = 0, nottaking = 0;

        if (wt[n - 1] <= W) {
            taking = val[n - 1] + f(W - wt[n - 1], val, wt, n - 1, dp);
        }

        nottaking = f(W, val, wt, n - 1, dp);

        return dp[n][W] = max(taking, nottaking);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return f(W, val, wt, n, dp);
    }
};
