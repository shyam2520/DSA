class Solution:
    def check(self, nums: List[int]) -> bool:
        for i in range(1,len(nums)): 
            if nums[i]<nums[i-1]: 
                break 
        else: 
            return True 
        
        peak_idx = i-1 
        while i%(len(nums))!=peak_idx: 
            if nums[i%len(nums)]>nums[(i+1)%len(nums)]:
                return False 
            i+=1
        return True