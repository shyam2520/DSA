class Solution {

public:
    bool solver(int rowidx, int colidx, int m, int n,
                vector<vector<char>>& board, int val) {
        int curr_val = val;
        // check in row
        bool row = true;
        for (int i = 0; i < n; i++) {
            
            if(board[rowidx][i]!='.' && board[rowidx][i] - '0' == curr_val) {
                row = false;
                break;
            }
        }
        // if(!row) continue;

        // check in col
        bool col = true;
        for (int i = 0; i < m; i++) {
            if(board[i][colidx]!='.' && board[i][colidx] - '0' == curr_val) {
                col = false;
                break;
            }
        }
        // if(!col) continue;

        // check in 3x3
        bool grid = true;
        for (int i = 3 * (rowidx / 3); i < 3 * (rowidx / 3) + 3; i++) {
            for (int j = 3 * (colidx / 3); j < 3 * (colidx / 3) + 3; j++) {
                if (board[i][j]!='.' && board[i][j] - '0' == curr_val) {
                    grid = false;
                    break;
                }
            }
        }
        // if(!grid) continue;

        return grid && row && col;
    }

    bool recursor(vector<vector<char>>& board, int ridx, int cidx) {

        // cout<<ridx<<" "<<cidx<<endl;
        if (ridx == board.size()) return true;
        if (cidx == board[0].size()) {
            return recursor(board, ridx + 1, 0);
        }
        if (board[ridx][cidx]!='.') {
            return recursor(board, ridx, cidx + 1);
        }


        for (int val = 1; val <= 9; val++) {
            if (solver(ridx, cidx, board.size(), board[0].size(), board, val)) 
            {
                board[ridx][cidx] = (char)(val + '0');
                if (recursor(board, ridx, cidx + 1)) return true;
                else board[ridx][cidx] = '.';

            }
        }
        // cout<<"false"<<endl;
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        recursor(board, 0, 0);
    }
};