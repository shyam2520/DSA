class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false)); 
        // do boundary traversal if O those will always remain O
        // mark them only visited rest all are marked X 
        // top && bottom boundary
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(board,visited,0,i);
            }
            if(board[m-1][i]=='O'){
                dfs(board,visited,m-1,i);
            }
        }

        // left & right boundary 
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(board,visited,i,0);
            }
            if(board[i][n-1]=='O'){
                dfs(board,visited,i,n-1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board,
    vector<vector<bool>>& visited,
    int i,int j)
    {
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]=='X' || visited[i][j]) return ; 
        // if(board[i][j]=='X;
        // if(visited[i][j]) return false;
        // board[i][j]='';
        visited[i][j]=true;
        // if()
        dfs(board,visited,i,j-1);
        dfs(board,visited,i,j+1);
        dfs(board,visited,i-1,j);
        dfs(board,visited,i+1,j);
        // board[i][j]=l&&r&&u&&d?'X':'O';


        // return board[i][j]=='X';
    }
};