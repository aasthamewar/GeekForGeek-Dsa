class Solution {
  public:
    // Helper function to merge and count inversions
    long long mergeAndCount(vector<int> &arr, int low, int mid, int high) {
        vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
        vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);
        
        int i = 0, j = 0, k = low;
        long long count = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                count += (left.size() - i);  // All remaining in left are greater
            }
        }

        while (i < left.size()) arr[k++] = left[i++];
        while (j < right.size()) arr[k++] = right[j++];

        return count;
    }

    long long mergeSortAndCount(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        long long count = 0;

        count += mergeSortAndCount(arr, low, mid);
        count += mergeSortAndCount(arr, mid + 1, high);
        count += mergeAndCount(arr, low, mid, high);

        return count;
    }

    long long inversionCount(vector<int> &arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
