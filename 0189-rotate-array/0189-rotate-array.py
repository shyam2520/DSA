class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k%len(nums) if k>=len(nums) else k
        nums[:]=reversed(nums)
        nums[:k]=reversed(nums[:k])
        nums[k:]=reversed(nums[k:]) 

        

        