from math import floor,ceil 

class Solution:
    def getSumDivisions(self,nums,divisor): 
        total = 0
        for val in nums: 
            total+=ceil(val/divisor) 
        return total 


    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        #1. range -  [1,max(nums)] all possible 
        #2. sum - all the divisons and result should be greater than the threshold 
        l,r=1,max(nums)
        res=-1 
        while l<=r: 
            mid=l+(r-l)//2
            if self.getSumDivisions(nums,mid)<=threshold: 
                res=mid
                r=mid-1
            else: 
                l=mid+1 

        return res 