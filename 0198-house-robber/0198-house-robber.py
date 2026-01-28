class Solution:
    def house(self,nums,idx,dp): 
        if idx>=len(nums): 
            return 0 
        if dp[idx]!=-1: 
            return dp[idx]
        # each rob and i+2 or don't and i+1 
        a = nums[idx]+self.house(nums,idx+2,dp) 
        b = self.house(nums,idx+1,dp)
        dp[idx] = max(a,b)
        return dp[idx]

    def rob(self, nums: List[int]) -> int:
        n = len(nums) 
        dp=[-1]*n 
        return self.house(nums,0,dp)