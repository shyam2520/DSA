class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res,curr_sum = float('-inf'),0 
        for i in nums: 
            curr_sum+=i 
            if curr_sum<i:
                curr_sum = i
            res=max(res,curr_sum)
        return res 
