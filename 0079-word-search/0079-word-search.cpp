class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // word - 1 to 15 char
        // board - m,n : 1-6 
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        // first find the first match char -> dfs 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word.front()){
                    bool res = dfs(visited,board,0,i,j,word);
                    if(res) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<bool>>& visited,vector<vector<char>>& board,int idx,
                        int i,int j,string& word)
    {
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || visited[i][j]){
            return false;
        } 
    
        if(board[i][j]!=word[idx]) return false;

        visited[i][j]=true;
        bool res = dfs(visited,board,idx+1,i+1,j,word) || 
                   dfs(visited,board,idx+1,i-1,j,word) ||
                   dfs(visited,board,idx+1,i,j+1,word) ||
                   dfs(visited,board,idx+1,i,j-1,word);
        visited[i][j]=false;
        return res;
               
    }
};