class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        // code here
        //brute force
        int maxipro=INT_MIN;
        // for(int i=0;i<arr.size();i++){
        //     int pro=1;
            
        //     for(int j=i;j<arr.size();j++){
        //         pro*=arr[j];
        //         maxipro=max(maxipro,pro);
        //     }
           
        // }
        // return maxipro;
        int max_so_far=nums[0];
        int min_so_far=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(max_so_far,min_so_far);
            }
            
            max_so_far=max(nums[i],nums[i]*max_so_far);
            min_so_far=min(nums[i],nums[i]*min_so_far);
            result=max(result,max_so_far);
        }
        return result;
        
    }
};