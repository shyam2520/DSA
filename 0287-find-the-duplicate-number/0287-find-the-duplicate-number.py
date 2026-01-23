class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # for each val -> idx -> -(nums[val])
        # for duplicates it already set that value to -(nums[val]) 
        # that would be the result 

        for val in nums: 
            idx = abs(val)
            if nums[idx]<0: 
                return idx
            else: 
                nums[idx]=-nums[idx]
        return -1