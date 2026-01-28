class Solution:
    def climb(self,idx,n,dp): 
        if(idx>n):
            return 0
        if(idx==n): 
            return 1
        if(dp[idx]!=-1): 
            return dp[idx] 
        dp[idx]=self.climb(idx+1,n,dp)+self.climb(idx+2,n,dp) 
        return dp[idx]
    def climbStairs(self, n: int) -> int:
        # each idx you can +1 or +2
        dp = [-1]*n 
        return self.climb(0,n,dp)