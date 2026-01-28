class Solution:
    def LIS(self,previdx,idx,nums,dp):
        if idx>=len(nums):
            return 0 
        if dp[previdx][idx]!=-1:
            return dp[previdx][idx]
        if nums[idx]>nums[previdx]:
            a=1+self.LIS(idx,idx+1,nums,dp)
            b=self.LIS(previdx,idx+1,nums,dp)
            dp[previdx][idx]=max(a,b)
            return dp[previdx][idx] 
        dp[previdx][idx]=self.LIS(previdx,idx+1,nums,dp)
        return dp[previdx][idx]

    def lengthOfLIS(self, nums: List[int]) -> int:
        # at each pt you can it can be start or increaseing sequence 
        # computer for each value LIS then you can use that reference again 
        ans = 0
        n = len(nums)
        dp = [ [ -1 for _ in range(n) ] for _ in range(n)]
        for i in range(len(nums)-1,-1,-1):
            res = 1+self.LIS(i,i+1,nums,dp)
            ans=max(res,ans)
        return ans