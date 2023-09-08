class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            vector<int> dict(10,0);
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.') continue;
                if(dict[board[i][j]-'0']) return false;
                dict[board[i][j]-'0']++;
            }
            dict.clear();
        }

        for(int i=0;i<n;i++)
        {
            vector<int> dict(10,0);
            for(int j=0;j<m;j++){
                if(board[j][i]=='.') continue;
                if(dict[board[j][i]-'0']) return false;
                dict[board[j][i]-'0']++;
            }
            dict.clear();
        }

        for(int row=0;row<m;row+=3){
            for(int col=0;col<n;col+=3){
                vector<int> dict(10,0);
                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){
                        if(board[i][j]=='.') continue;
                        if(dict[board[i][j]-'0']) return false;
                        dict[board[i][j]-'0']++;
                    }
                }
            }

        }


        return true;
    }
};