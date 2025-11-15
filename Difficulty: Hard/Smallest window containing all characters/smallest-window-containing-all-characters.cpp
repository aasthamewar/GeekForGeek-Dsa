class Solution {
  public:
    string smallestWindow(string s, string p) {
        if (p.size() > s.size()) return "";

        vector<int> need(256, 0);
        vector<int> window(256, 0);

        // Build frequency of p
        for (char c : p) need[c]++;

        int required = p.size();  // total chars needed (including duplicates)
        int formed = 0;           // how many chars are satisfied

        int left = 0, minLen = INT_MAX, startIndex = -1;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need[c] > 0 && window[c] <= need[c]) {
                formed++; 
            }

            // When current window is valid (contains all chars)
            while (formed == required) {
                // Update result if smaller window found
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // Try shrinking
                char leftChar = s[left];
                window[leftChar]--;
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        if (startIndex == -1) return "";
        return s.substr(startIndex, minLen);
    }
};
