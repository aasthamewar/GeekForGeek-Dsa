class Solution {
public:
    vector<int> rabinKarp(string &text, string &pattern) {
        int n = text.size();
        int m = pattern.size();

        vector<int> result;

        if (m > n) return result;

        const long long base = 256;        // character range
        const long long mod  = 1e9 + 7;    // large prime

        long long patHash = 0, txtHash = 0, power = 1;

        // Compute base^(m-1)
        for (int i = 0; i < m - 1; i++)
            power = (power * base) % mod;

        // Compute initial pattern hash & first window hash
        for (int i = 0; i < m; i++) {
            patHash = (patHash * base + pattern[i]) % mod;
            txtHash = (txtHash * base + text[i]) % mod;
        }

        // Slide the window over the text
        for (int i = 0; i <= n - m; i++) {

            // If hash matches, verify substring to avoid collision
            if (patHash == txtHash) {
                if (text.substr(i, m) == pattern)
                    result.push_back(i);
            }

            // Roll the hash except at last window
            if (i < n - m) {
                txtHash = (txtHash - text[i] * power % mod + mod) % mod;
                txtHash = (txtHash * base + text[i + m]) % mod;
            }
        }

        return result;
    }
};
