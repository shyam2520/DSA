class Solution:
    def __init__(self): 
        self.res=0
    def dfs(self,dp,m,n,i,j):
        if i==m or j==n:
            return 0
        if i==m-1 and j==n-1:
            return 1
        if dp[i][j]!=-1: 
            return dp[i][j]
        dp[i][j]=self.dfs(dp,m,n,i+1,j)+self.dfs(dp,m,n,i,j+1)
        return dp[i][j]

    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1]*n for _ in range(m)]
        return self.dfs(dp,m,n,0,0)
        # return self.res
