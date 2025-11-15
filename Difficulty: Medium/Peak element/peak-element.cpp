class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is less than the next element,
            // then the peak lies on the right side
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            else {
                // Peak is at mid or on the left
                high = mid;
            }
        }

        // low == high is the peak index
        return low;
    }
};
