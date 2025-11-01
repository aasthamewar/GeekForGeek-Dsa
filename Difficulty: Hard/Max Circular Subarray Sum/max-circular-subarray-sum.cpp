class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        int total = 0;

        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for (int i = 0; i < n; i++) {
            total += arr[i];

            // Kadane's for max subarray
            curMax = max(arr[i], curMax + arr[i]);
            maxSum = max(maxSum, curMax);

            // Kadane's for min subarray
            curMin = min(arr[i], curMin + arr[i]);
            minSum = min(minSum, curMin);
        }

        // If all elements are negative, return maxSum only
        if (maxSum < 0)
            return maxSum;

        // Otherwise, maximum of non-wrap and wrap cases
        return max(maxSum, total - minSum);
    }
};
