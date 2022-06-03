class NumMatrix {
    vector<vector<int>> matrix_copy;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++ )
            {
                matrix[i][j]=matrix[i][j]+matrix[i][j-1];
            }
        }
        matrix_copy=matrix;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        for(int i=row1;i<=row2;i++)
        {
            if(col1==0) res+=matrix_copy[i][col2];
            else res+=(matrix_copy[i][col2]-matrix_copy[i][col1-1]);
        }
        return res;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */