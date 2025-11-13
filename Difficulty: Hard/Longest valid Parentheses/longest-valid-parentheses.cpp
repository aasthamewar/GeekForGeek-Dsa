
class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int maxLen = 0;
        stack<int> st;
        st.push(-1);  // base index to handle first valid substring

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (!st.empty()) {
                    maxLen = max(maxLen, i - st.top());
                } else {
                    st.push(i); // reset base for next valid substring
                }
            }
        }
        return maxLen;
        
    }
};