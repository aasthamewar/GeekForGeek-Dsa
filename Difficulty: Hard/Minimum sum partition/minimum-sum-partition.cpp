class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        for (int val : arr)
            totalSum += val;

        int sum = totalSum;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        // Fill the DP array
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        // Find the closest possible sum to totalSum / 2
        int minDiff = INT_MAX;
        for (int s1 = totalSum / 2; s1 >= 0; s1--) {
            if (dp[s1]) {
                minDiff = totalSum - 2 * s1;
                break;
            }
        }

        return minDiff;
    }
};
