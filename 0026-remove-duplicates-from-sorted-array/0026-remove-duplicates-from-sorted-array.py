class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        anc = 0 
        n = len(nums)
        for i in range(n): 
            if i>0 and nums[i]==nums[i-1]: 
                continue 
            else: 
                nums[anc]=nums[i] 
                anc+=1 
        return anc

            