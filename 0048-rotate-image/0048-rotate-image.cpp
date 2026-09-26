class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix & reverse each row 
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                // swap values 
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++) reverse(begin(matrix[i]),end(matrix[i]));
        // return matrix;
    }
};