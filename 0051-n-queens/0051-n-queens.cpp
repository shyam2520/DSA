class Solution {
public:
    vector<vector<string>> res;
    void genqueen(int n,int rowidx,vector<string> board,unordered_set<int> col,
    unordered_set<int> ldiag,unordered_set<int> rdiag){
        if(!n) {
            res.push_back(board);
            return;
        }
        if(rowidx==board.size()) return;
        
        for(int i=0;i<board[0].size();i++){
            int x=rowidx;
            int y=i;
            if(col.contains(y) || ldiag.contains(x+y) || rdiag.contains(y-x)) continue;
            else{
                board[x][y]='Q';
                col.insert(y);ldiag.insert(x+y);rdiag.insert(y-x);
                genqueen(n-1,rowidx+1,board,col,ldiag,rdiag);
                col.erase(y);ldiag.erase(x+y);rdiag.erase(y-x);
                board[x][y]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        //ldiag = i+j , rdiag= abs(i-j)
        // cout<<temp.size()<<" "<<temp[0].size()<<endl;
        unordered_set<int> col,ldiag,rdiag;
        genqueen(n,0,temp,col,ldiag,rdiag);
        return res;
    }
};