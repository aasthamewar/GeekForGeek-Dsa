class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<arr.size();i++){
            
            sum+=arr[i];
            
            if(sum>maxi){
                maxi=sum;
            }
            
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
        
    }
};