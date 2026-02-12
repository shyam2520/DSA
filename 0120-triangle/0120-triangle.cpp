class Solution {
public:

    int recursion(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        if(i==triangle.size()-1){
            return j<triangle[i].size()?triangle[i][j]:INT_MAX;
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int d = recursion(triangle,i+1,j,dp);
        int dr = recursion(triangle,i+1,j+1,dp);
        
        return dp[i][j]=triangle[i][j]+min(d,dr);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int  m=triangle.size();
        // int n = 
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
        return recursion(triangle,0,0,dp);
    }
};