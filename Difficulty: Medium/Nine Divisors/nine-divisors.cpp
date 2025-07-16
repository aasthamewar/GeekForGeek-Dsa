class Solution {
  public:
     bool has9div(int x){
      // finding divs of the numbers. 
      int cnt = 0;
      
      for(int i=1; i*i<=x; i++){
          if(x%i==0 && x!=i*i) cnt+=2;
          else if(x%i==0) cnt++;
          if(cnt>9) return false;
      }
      
      return cnt==9;
      
  }
  
  
    int countNumbers(int n) {
        // Code Here
        int ans = 0;
        
        // as from example 36 is the first one. 
        for(int i=6; i*i<=n; i++){
            if(has9div(i*i)){
                ans++;
            }
        }
        return ans;
    }
};