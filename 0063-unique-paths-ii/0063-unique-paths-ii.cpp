class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(grid,0,0,dp);
    }

    int dfs(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& dp){
        if(x==grid.size() || y==grid[0].size() || grid[x][y]==1) return 0;
        if(x==grid.size()-1 && y==grid[0].size()-1) return 1;
        if(dp[x][y]!=-1) return dp[x][y]; 
        // if()
        return dp[x][y]=dfs(grid,x+1,y,dp)+dfs(grid,x,y+1,dp);
    }

};