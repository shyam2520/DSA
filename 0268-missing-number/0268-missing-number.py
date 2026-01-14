class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums_xor=nums[0]
        res = 0^len(nums) 
        for i in range(1,len(nums)): 
            nums_xor=nums_xor ^ nums[i]
            res = res ^ i

        return nums_xor ^ res


        