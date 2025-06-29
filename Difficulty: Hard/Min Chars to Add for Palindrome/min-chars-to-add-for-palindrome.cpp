class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int size=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        s+='$';
        s+=rev;
        int n=s.size();
        vector<int>lps(n,0);
        int pre=0,suf=1;
        while(suf<s.size()){
            //matched
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                suf++;
                pre++;
            }
            //unmatched
            else{
                if(pre==0){
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return size-lps[n-1];
    }
};
