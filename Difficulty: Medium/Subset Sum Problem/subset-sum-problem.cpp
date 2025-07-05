class Solution {
  public:
     bool check(int i,int sum,vector <int> &arr)
    {
        if (sum==0) return true;
        if (sum <0 || i==arr.size()) return false;
        if (check(i+1,sum-arr[i],arr)) return true;
        if (check(i+1,sum,arr)) return true;
        return false;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        return check (0,sum,arr);
    
    }
};