class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1,rowidx=-1;
        while(l<=r){
            int mid =l+(r-l)/2; 
            if(matrix[mid].back()<target) l=mid+1;
            else{
                rowidx=mid;
                r=mid-1;
            }
        }
        if(rowidx==-1) return false;
        l=0,r=matrix[0].size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[rowidx][mid]==target) return true;
            if(matrix[rowidx][mid]>target) r=mid-1;
            else l=mid+1;
        }   
        return false;
    }
};