class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        vector<int> spiral;
        int n=mat.size();
        int m=mat[0].size();
        int left=0;
        int right=m-1;
        int top=0;
        int bottom=n-1;
        
        
        while(left<=right && top<=bottom){
            // move from left to right(in top)
            for(int col=left;col<=right;col++){
                spiral.push_back(mat[top][col]);
            }
            top++;
            
            //move from top to bottom(in last col)
            for(int row=top;row<=bottom;row++){
                spiral.push_back(mat[row][right]);
            }
            right--;
            
            //move right to left
            if(top<=bottom){
                for(int col=right;col>=left;col--){
                    spiral.push_back(mat[bottom][col]);
                }
                bottom--;
            }
            //move bottom to top
            if(left<=right){
                for(int row=bottom;row>=top;row--){
                    spiral.push_back(mat[row][left]);
                }
                left++;
            }
        }
        return spiral;
    }
};