class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n%k!=0)return false;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(freq[arr[i]]==0)continue;
            for(int j=0;j<k;j++){
                if(freq[arr[i]+j]==0)return false;
                freq[arr[i]+j]--;
            }
        }
        return true;
    }
};