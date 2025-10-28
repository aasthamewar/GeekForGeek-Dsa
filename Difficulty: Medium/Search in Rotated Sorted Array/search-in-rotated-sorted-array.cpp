class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,end=nums.size()-1;
        while(low<=end){
            int mid=low+(end-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            //now will check in left sorted part
            if(nums[mid]>=nums[low]){
                //check the target even exist in the left part 
                if(target>=nums[low] && target<nums[mid]){
                    end = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            //now will check in right sorted part
            else{
                if(target<=nums[end]  && target>nums[mid]){
                    low = mid+1;
                }
                else{
                    end = mid-1;
                }
            }

        }
        return -1;
    }
};