class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
         int n = arr.size();
        vector<int> res(n, -1); // Default is -1
        stack<int> st; // Stack to store indices

        for (int i = 0; i < n; ++i) {
            // While stack is not empty and current element > element at index on top of stack
            while (!st.empty() && arr[i] > arr[st.top()]) {
                res[st.top()] = arr[i]; // Next greater for index on top
                st.pop();
            }
            st.push(i); // Push current index
        }

        return res;
        
    }
};