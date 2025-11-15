class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        for(int col=0;col<n;col++){
            int l=0,r=m-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(matrix[mid][col]==target) return true;
                if(matrix[mid][col]>target) r=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};