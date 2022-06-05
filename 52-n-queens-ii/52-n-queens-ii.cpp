class Solution {
    int res=0;
    public:
    int totalNQueens(int n) {
        vector<string> temp;
        string s=string(n,'.');
        for(int i=0;i<n;i++) temp.push_back(s);

        backtracking(temp,0);
        
        return res;
        
    }
    
    void backtracking(vector<string>& temp,int row)
    {
        if(row==temp.size())
        {
            res++;
            return ;
        }
        
        for(int i=0;i<temp.size();i++)
        {
            temp[row][i]='Q';
            if(validQueen(temp,row,i))
                backtracking(temp,row+1);
            temp[row][i]='.';
        }
    }
    
    bool validQueen(vector<string>& temp,int row,int col)
    {
        for(int i=0;i<temp.size();i++)
            if(temp[row][i]=='Q' && i!=col) return false;
        
        for(int i=0;i<temp.size();i++)
            if(temp[i][col]=='Q' && i!=row) return false;
        
        int diff=col-row,sum=col+row;
        for(int i=0;i<temp.size();i++)
        {
            int r=i;
            int c=i+diff;
            if(r>=0 && c>=0 && r<temp.size() && c<temp.size() && temp[r][c]=='Q' && r!=row && c!=col) return false;
        }
        
        for(int i=0;i<temp.size();i++)
        {
            int r=i;
            int c=sum-i;
            if(r>=0 && c>=0 && r<temp.size() && c<temp.size() && temp[r][c]=='Q' && r!=row && c!=col) return false;       
        }
        return true;
    }
};