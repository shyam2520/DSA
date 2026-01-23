class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        l,res = -1, 0
        nums.append(0)
        for i in range(len(nums)):
            if nums[i]==1: 
                if l==-1: 
                    l=i 
            else: 
                if l!=-1: 
                    res = max([res,i-l])
                l=-1 

        return res
            