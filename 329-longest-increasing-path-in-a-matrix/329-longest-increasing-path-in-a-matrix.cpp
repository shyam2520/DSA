class Solution {
    int res=0;
    vector<vector<int>> dp;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),INT_MIN));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                dp[i][j]=dfs(matrix,i,j,-1);
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
    int  dfs(vector<vector<int>>& matrix,int i,int j,int prev )
    {
        if(i<0 || j<0 ||i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=prev) 
        {
            
            // res=max(res,len);
            return 0;
        }
        
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        
        
        int a=dfs(matrix,i+1,j,matrix[i][j]);
        int b=dfs(matrix,i-1,j,matrix[i][j]);
        int c=dfs(matrix,i,j+1,matrix[i][j]);
        int d=dfs(matrix,i,j-1,matrix[i][j]);
        dp[i][j]=1+max({a,b,c,d});
        // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        return dp[i][j];
        
    }
};