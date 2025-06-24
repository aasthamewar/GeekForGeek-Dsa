class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        string stack="";
        for(char c:s){
            while(!stack.empty() && k>0 && stack.back()<c){
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while (k > 0) {
        stack.pop_back();
        k--;
    }
        return stack;
    }
};
