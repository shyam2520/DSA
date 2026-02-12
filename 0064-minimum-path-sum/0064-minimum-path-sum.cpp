class Solution {
public:
    int traversal(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==grid.size() || j==grid[0].size()) return INT_MAX;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int r = traversal(grid,i,j+1,dp);
        int d = traversal(grid,i+1,j,dp);
        return dp[i][j]=min(r,d)+grid[i][j];

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // return traversal(grid,0,0,dp);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) dp[i][j]=grid[i][j];
                else{
                    dp[i][j]= grid[i][j]+min((i+1<m?dp[i+1][j]:INT_MAX),(j+1<n?dp[i][j+1]:INT_MAX));
                }
            }
        }
        return dp[0][0];
    }
};