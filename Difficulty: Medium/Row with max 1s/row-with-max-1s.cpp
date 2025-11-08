// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int row=0,col=m-1;
        int maxrow=-1;
        
        while(row<n && col>=0){
            if(arr[row][col]==1){
                maxrow=row;
                col--;
            }else{
                row++;
            }
        }
        return maxrow;
    }
};