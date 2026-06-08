class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int start=0;
        int end=n-1;
        if(arr[start]<=arr[end]){
            return 0;
        }
        while(start<=end){
            int mid=start+(end-start)/2;
            //checking for mid , kya pta vo hi min ele ho
            if(arr[mid]>arr[mid+1]){
                return mid+1;
            }
            if(arr[mid]<arr[mid-1]){
                return mid;
            }
            
            if(arr[mid]>arr[end]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return 0;
    }
};
