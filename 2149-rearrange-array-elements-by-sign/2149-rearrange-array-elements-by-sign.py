class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0]*n
        pos,neg=0,1 
        for i in nums: 
            if i<0:
                res[neg]=i 
                neg+=2 
            else: 
                res[pos]=i 
                pos+=2 
        return res