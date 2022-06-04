class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s=string(n,'.');
        vector<string> temp;
        for(int i=0;i<n;i++) temp.push_back(s);
        backtracking(res,temp,0,n);
        return res;
    }
    
    void backtracking(vector<vector<string>>& res,vector<string>& temp,int row, int n)
    {
        if(row==n) 
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            temp[row][i]='Q';
            if(validQueen(row,i,temp)) 
                backtracking(res,temp,row+1,n);
            temp[row][i]='.';
        }
    }
    
    bool validQueen(int row,int col,vector<string>& temp)
    {
        int n=temp.size();
        // int count=0;
        for(int i=0;i<n;i++)  if(temp[row][i]=='Q' && i!=col ) return false; 
        for(int i=0;i<n;i++) if(temp[i][col]=='Q' && i!=row) return false;
        
        int diff=(col-row) ,sum=row+col;
        for(int i=0;i<n;i++)
        {
            int r=i;
            int c=i+diff;
            if(r>=0 && c>=0 && r<n && c<n && temp[r][c]=='Q' && r!=row && c!=col) return false;
        }
        
        for(int i=0;i<n;i++)
        {
            int r=i;
            int c=sum-r;
            if(r>=0 && c>=0 && r<n && c<n && temp[r][c]=='Q' && r!=row && c!=col) return false;
            
        }
        // cout<<row<<" "<<col<<endl;
        return true;
        
    }
};