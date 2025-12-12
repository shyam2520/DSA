class Solution {
public:
    bool search(vector<vector<char>>& board,map<pair<int,int>,bool>& umap,int i,int j,int idx,string& word){
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || umap[{i,j}] || board[i][j]!=word[idx]) return false;

        umap[{i,j}]=true;
        bool res = search(board,umap,i+1,j,idx+1,word) ||
        search(board,umap,i-1,j,idx+1,word) ||
        search(board,umap,i,j-1,idx+1,word) ||
        search(board,umap,i,j+1,idx+1,word);
        umap[{i,j}]=false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        map<pair<int,int>,bool> umap;
        // forloop to find the first char and then expand
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && search(board,umap,i,j,0,word)){
                    return true;
                } 
            }
        }
        return false;
    }
};