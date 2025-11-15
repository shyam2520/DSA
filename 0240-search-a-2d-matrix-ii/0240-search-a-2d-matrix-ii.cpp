class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0){
            int val = matrix[row][col];
            if(val==target) return true;
            if(val>target) col--; 
            else row++;
        }
        return false;
    }
};