class Solution:
    def house(self,nums,idx,end,dp): 
        if idx>end: 
            return 0    
        if dp[idx]!=-1:
            return dp[idx]


        a = nums[idx]+self.house(nums,idx+2,end,dp)
        b = self.house(nums,idx+1,end,dp)
        dp[idx]=max(a,b)
        return dp[idx]

    def rob(self, nums: List[int]) -> int:
        if len(nums)<3:
            return max(nums)
        dp=[-1]*len(nums) 
        a = self.house(nums,0,len(nums)-2,dp)
        dp=[-1]*len(nums)
        b = self.house(nums,1,len(nums)-1,dp)
        return max(a,b)