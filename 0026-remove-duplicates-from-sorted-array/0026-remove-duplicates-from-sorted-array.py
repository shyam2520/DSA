class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        anc=0
        prev = -1000
        for i in range(len(nums)): 
            if nums[i]>prev: 
                nums[anc]=nums[i]
                prev = nums[i]
                anc+=1
        return anc

            