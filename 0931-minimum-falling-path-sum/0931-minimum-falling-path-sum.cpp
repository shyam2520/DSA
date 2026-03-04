class Solution {
public:

    int fallThrough(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>& dp){
        if(row==matrix.size()) return 0;
        if(col>=matrix[0].size() || col<0) return INT_MAX;
        if(dp[row][col]!=INT_MIN) return dp[row][col];
        int l = fallThrough(matrix,row+1,col-1,dp);
        int r = fallThrough(matrix,row+1,col+1,dp);
        int m = fallThrough(matrix,row+1,col,dp);
        return dp[row][col]=matrix[row][col]+min({l,r,m});
    }

    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int mini = INT_MAX;
        int n=matrix[0].size(),m=matrix.size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MIN));
        for(int i=0;i<n;i++){
            int cost = fallThrough(matrix,0,i,dp);
            mini = min(mini,cost);
        }
        return mini;
    }
};