class Solution {
public:
    // Function to delete middle element of a stack.
    void solve(stack<int>& s, int count, int size) {
        // Base case: reached the middle
        if (count == size / 2) {
            s.pop();
            return;
        }
        
        int num = s.top();
        s.pop();
        
        solve(s, count + 1, size);
        
        s.push(num);
    }

    void deleteMid(stack<int>& s) {
        int n = s.size();
        int count = 0;
        solve(s, count, n);
    }
};
