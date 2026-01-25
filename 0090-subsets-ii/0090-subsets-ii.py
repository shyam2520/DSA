class Solution:
    
    def recursion(self,nums,idx,res,temp):
        if idx==len(nums): 
            return 
        for i in range(idx,len(nums)): 
            if i>idx and nums[i]==nums[i-1]:
                continue
            temp.append(nums[i])
            res.append(temp.copy()) 
            self.recursion(nums,i+1,res,temp)
            temp.pop()

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        nums.sort()
        self.recursion(nums,0,res,[])
        return res    