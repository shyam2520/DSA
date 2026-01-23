class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt,val = 0,0
        for ele in nums:
            if cnt==0: 
                cnt=1 
                val=ele 
            elif ele==val: 
                cnt+=1 
            else: 
                cnt-=1 
        return val