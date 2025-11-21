class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        int cnt=0,ans=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                ans=max(ans,cnt);
                i++;
            }
            else if(arr[i]>dep[j]){
                cnt--;
                j++;
            }
        }
        return ans;
    }
};
