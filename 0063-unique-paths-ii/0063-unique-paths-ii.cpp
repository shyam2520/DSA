class Solution {
public:
    int paths(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp)
    {
        if(i==grid.size() || j==grid[0].size() || grid[i][j]==1) return 0; 
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=paths(grid,i+1,j,dp)+paths(grid,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // dfs + dp 
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return paths(grid,0,0,dp);
    }
};