class Solution:

    def dfs(self,obstacleGrid,i,j,dp): 
        m,n = len(obstacleGrid),len(obstacleGrid[0])
        if i<0 or j<0 or i==m or j==n or obstacleGrid[i][j]==1:
            return 0
        if i==m-1 and j==n-1:
            return 1 
        if dp[i][j]!=-1: 
            return dp[i][j]

        dp[i][j]=self.dfs(obstacleGrid,i+1,j,dp) +  self.dfs(obstacleGrid,i,j+1,dp)
        return dp[i][j]

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # i,j -> bottom or right 
        # no reursive loops & dp to keep track of repeated positions 
        i,j = 0,0 
        m,n = len(obstacleGrid),len(obstacleGrid[0])
        dp = [ [-1 for i in range(n)] for _ in range(m)]
        return self.dfs(obstacleGrid,i,j,dp)