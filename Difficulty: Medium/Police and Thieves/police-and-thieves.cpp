class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int police=0,thief=0;
        while(police<n && arr[police]!='P')police++;
        while(thief<n && arr[thief]!='T')thief++;
        int cnt=0;
        while( police<n && thief<n){
            if(abs(police-thief)<=k){
                cnt++;
                police++;
                thief++;
            }
            else if(thief<n&&thief<police)thief++;
            else if(police<n && police<thief)police++;
            while(police<n && arr[police]!='P')police++;
            while(thief<n && arr[thief]!='T')thief++;
        }
        return cnt;
    }
};