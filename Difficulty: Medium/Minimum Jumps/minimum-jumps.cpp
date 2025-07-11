class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;        // Already at the end
        if (arr[0] == 0) return -1;  // Can't move anywhere

        int maxReach = arr[0];      // Max index reachable
        int steps = arr[0];         // Steps available in current jump
        int jumps = 1;              // We always need at least one jump (if n > 1)

        for (int i = 1; i < n; ++i) {
            if (i == n - 1) return jumps;  // Reached the end

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1;  // Cannot move further
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
