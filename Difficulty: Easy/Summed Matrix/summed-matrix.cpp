
class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
         long long res;

        if (q < 2 || q > (2 * n))
          return 0;
        if (n >= q)
          n = q - 1;
        res = 2 * n - q + 1;
        return res;
    }
};