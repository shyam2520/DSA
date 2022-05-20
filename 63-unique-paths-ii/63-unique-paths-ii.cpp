class Solution {
    int res=0;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        // cout<<dp.size()<<" "<<dp[0].size()<<endl;
        return dfs(grid,0,0,dp);
        // return res;
    }
    
    int  dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1)
            return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;

        // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        
        if(dp[i][j]) return dp[i][j];
        
        // grid[i][j]=1;
        
        dp[i][j]=dfs(grid,i,j+1,dp) +dfs(grid,i+1,j,dp);
        
        // grid[i][j]=0;
        return dp[i][j];
    }
};