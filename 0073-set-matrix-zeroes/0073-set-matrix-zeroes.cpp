class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstrow=false,firstcol=false;
        for(int i=0;i<matrix[0].size();i++){
            if(!matrix[0][i]) {
                firstrow=true;
                matrix[0][i]=0;
            }
        }

        for(int i=0;i<matrix.size();i++){
            if(!matrix[i][0]) {
                firstcol=true;
                matrix[i][0]=0;
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(!matrix[i][j]) {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                } 
            }
        }

        for(int i=1;i<matrix.size();i++){
            if(!matrix[i][0]) for(int j=0;j<matrix[0].size();j++) matrix[i][j]=0;
        }
        
        for(int j=1;j<matrix[0].size();j++){
            if(!matrix[0][j]) for(int i=0;i<matrix.size();i++) matrix[i][j]=0;
        }

        if(firstrow){
            for(int j=0;j<matrix[0].size();j++) matrix[0][j]=0;
        }
        if(firstcol){
            for(int i=0;i<matrix.size();i++) matrix[i][0]=0;
        }

    }
};