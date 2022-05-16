class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        if(m==1 && n==1 && grid[0][0]==0)return 1;
        queue<pair<int,int>> q;
        // cout<<"chec"<<endl;
        q.push({0,0});
        grid[0][0]=1;
        int len=1;
        int row,col;
        // cout<<dir.size()<<endl;
        // pair<int,int> temp;
        while(q.size())
        {
            for(int i=q.size();i>0;i--)
            {
                // cout<<i<<endl;
                row=q.front().first;
                col=q.front().second;
                q.pop();
                for(int i=0;i<8;i++)
                {
                    int nrow=row+dir[i].first;
                    int ncol=col+dir[i].second;
                    // cout<<nrow<<" "<<ncol<<endl;
                    if(nrow==m-1 && ncol==n-1) return len+1;
                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]!=1)
                    {
                         // cout<<nrow<<" "<<ncol<<endl;

                        q.push({nrow,ncol});
                        grid[nrow][ncol]++;
                    }
                }
            }
            len++;
        }
        return -1;
    }
};