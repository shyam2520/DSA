class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        anc = 0 
        for val in nums:
            if val: 
                nums[anc]=val 
                anc+=1 
        
        for i in range(anc,len(nums)): 
            nums[i]=0
        
        