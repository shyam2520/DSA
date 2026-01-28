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
        res = 0
        next1,next2=None,None 
        for i in range(n-1,-1,-1):
            take,notake = nums[i],0
            if i+2<n: 
                take+=next2
            if i+1<n:
                notake+=next1
            curr=max(take,notake)
            res=max(res,curr)
            next2=next1 
            next1=curr
        return res
        # return self.house(nums,0,dp)