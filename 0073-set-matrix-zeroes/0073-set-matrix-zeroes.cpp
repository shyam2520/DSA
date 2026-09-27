class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // first all the columsn indicate the columns which need to be 0 
        // first column all rows indicate all the rows which needs to be 0 
        // since first is row is forst , if rows needs to be 0 thats over lapping 
        // extra variable to store that 
        int row1=-1;
        int m = matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    if(i==0) {
                        row1=0;
                        matrix[0][j]=0;
                    }
                    else{
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        // update rows & columsn apart from the first row 
        for(int j=1;j<n;j++){
            if(!matrix[0][j]) for(int i=1;i<m;i++) matrix[i][j]=0;
        }
        // update rows apart from first row 
        for(int i=1;i<m;i++){
            if(!matrix[i][0]) for(int j=1;j<n;j++) matrix[i][j]=0;
        }
        if(!matrix[0][0]) for(int i=0;i<m;i++) matrix[i][0]=0;
        if(!row1) for(int j=0;j<n;j++) matrix[0][j]=0;
    }
};