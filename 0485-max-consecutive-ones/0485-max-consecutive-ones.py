class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        cnt,res=0,0 
        nums.append(0)
        i=0
        while i<len(nums): 
            if nums[i]: 
                cnt+=1
            else: 
                res = max(res,cnt) 
                cnt=0
                while i<len(nums) and nums[i]==0: 
                    i+=1 
                i-=1

            i+=1 
        return res