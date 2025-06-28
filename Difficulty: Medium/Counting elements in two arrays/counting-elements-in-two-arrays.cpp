class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>freq(100001,0);
        for(int i=0;i<b.size();i++){
            freq[b[i]]++;
        }
        vector<int>ans(a.size());
        for(int i=0;i<100001;i++){
            freq[i]+=freq[i-1];
        }
        for(int i=0;i<a.size();i++){
            ans[i]=freq[a[i]];
        }
        return ans;
    }
};