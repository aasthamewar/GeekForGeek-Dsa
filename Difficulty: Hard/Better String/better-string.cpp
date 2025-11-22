// User function Template for C++

class Solution {
  public:
  long long countDistinctSubSeq(const string &s){
      int n=s.size();
      vector<long long> dp(n+1,0);
      dp[0]=1;
      
      vector<int> last(256,-1);
      
      for(int i=1;i<=n;i++){
          char c=s[i-1];
          dp[i]=2*dp[i-1];
          
          if(last[c]!=-1){
              dp[i]-=dp[last[c]-1];
          }
          last[c]=i;
      }
      return dp[n];
  }
    string betterString(string &s1, string &s2) {
        // code here
        long long c1=countDistinctSubSeq(s1);
        long long c2=countDistinctSubSeq(s2);
        
        if(c1>=c2)return s1;
        return s2;
    }
};