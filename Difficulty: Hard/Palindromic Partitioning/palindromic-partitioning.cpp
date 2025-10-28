class Solution {
public:
    int palPartition(string s) {  // <-- renamed from minCut
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // Step 1: Build palindrome table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                }
            }
        }

        // Step 2: Compute minimum cuts
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;  // whole substring is palindrome
            } else {
                dp[i] = i;  // maximum possible cuts
                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
