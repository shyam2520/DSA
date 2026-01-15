class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        prefix,suffix = 1,1 
        res=float("-INF")
        for i in range(len(nums)):
            if prefix==0: 
                res=max(res,0)
                prefix=1 
            elif suffix==0: 
                res=max(res,0)
                suffix=1
            
            prefix=prefix*nums[i] 
            suffix=suffix*nums[len(nums)-1-i]
            res=max(res,max(prefix,suffix))
        return res