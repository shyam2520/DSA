class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        res,cnt=0,0 
        for i in nums: 
            if not(i): 
                cnt=0
            else: 
                cnt+=1 
            res=max([res,cnt])
        return res