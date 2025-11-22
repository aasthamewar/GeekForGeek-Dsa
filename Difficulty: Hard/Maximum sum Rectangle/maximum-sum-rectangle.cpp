class Solution {
public:
    // Standard Kadane’s Algorithm for max subarray sum
    int kadane(vector<int>& arr) {
        int maxEnd = arr[0], maxSoFar = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxEnd = max(arr[i], maxEnd + arr[i]);
            maxSoFar = max(maxSoFar, maxEnd);
        }
        return maxSoFar;
    }

    int maxRectSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxi = INT_MIN;

        // Fix left column boundary
        for (int left = 0; left < m; left++) {

            vector<int> temp(n, 0); // temporary array to store row sums

            // Fix right column boundary
            for (int right = left; right < m; right++) {

                // Add the column 'right' to temp
                for (int row = 0; row < n; row++) {
                    temp[row] += mat[row][right];
                }

                // Find the max subarray sum for this "compressed" array
                maxi = max(maxi, kadane(temp));
            }
        }

        return maxi;
    }
};
