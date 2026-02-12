class Solution {
public:
    int mod = 2*1e9;
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // dfs + dp 
        int m=grid.size(),n=grid[0].size(); 
        // vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> next(n);
        vector<int> curr(n);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1) curr[j]=0;
                else if(i==m-1 && j==n-1) curr[j]=1;
                else{
                    curr[j]=((long)((i+1<m?next[j]:0)%mod)+(long)((j+1<n?curr[j+1]:0)%mod))%mod;
                }
            }
            next=curr;
            curr.resize(n,0);
        }
        return next[0];

        // return paths(grid,0,0,dp);
    }
};