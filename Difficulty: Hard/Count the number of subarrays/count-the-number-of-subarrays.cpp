// User function Template for C++
class Solution {
  public:
    long long countAtMost(vector<int>& A, long long X) {
    long long count = 0, sum = 0;
    int left = 0;
    for (int right = 0; right < A.size(); right++) {
        sum += A[right];
        while (sum > X && left <= right) {
            sum -= A[left++];
        }
        count += (right - left + 1);  // all subarrays ending at right
    }
    return count;
}

long long countSubarray(int N, vector<int>& A, long long L, long long R) {
    return countAtMost(A, R) - countAtMost(A, L - 1);
}
};