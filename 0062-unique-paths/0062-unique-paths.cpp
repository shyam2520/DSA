class Solution {
    int res=0;
    
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dfs(m,n,0,0,dp);
        return dp[0][0];
    }

    int dfs(int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if((i==m-1 && j==n-1))  return  1;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=dfs(m,n,i+1,j,dp)+dfs(m,n,i,j+1,dp);
        return dp[i][j];
    }
    
};