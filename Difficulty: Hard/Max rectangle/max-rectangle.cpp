#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> height(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // Step 1: Update histogram heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    height[j] += 1;
                else
                    height[j] = 0;
            }

            // Step 2: Compute largest rectangle for this histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
