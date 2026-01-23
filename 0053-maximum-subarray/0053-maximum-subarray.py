class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res,curr_sum=0,0 
        for val in nums: 
            if curr_sum+val<=val: 
                curr_sum=val 
            else: 
                curr_sum+=val 
            res=max([curr_sum,res])
        return res