class Solution {
public:
    vector<int> search(string pat, string txt) {
        int n = txt.size();
        int m = pat.size();
        vector<int> result;

        // Step 1: Build LPS (Longest Prefix Suffix) array for pattern
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
            }
        }

        // Step 2: Search pattern in text using the LPS table
        i = 0; // index for txt
        int j = 0; // index for pat
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++; j++;
            }

            if (j == m) { 
                result.push_back(i - j); // found match
                j = lps[j - 1]; // continue searching
            } 
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return result;
    }
};
