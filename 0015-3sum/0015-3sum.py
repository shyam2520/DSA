class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums[:] = sorted(nums)
        n = len(nums)
        res = []
        for i in range(n): 
            while i>0 and i<n and nums[i]==nums[i-1]:
                i+=1
            j = i+1
            k = n-1 
            while j<k: 
                curr_sum = nums[i]+nums[j]+nums[k] 
                if curr_sum==0: 
                    res.append([nums[i],nums[j],nums[k]])
                    j+=1
                    k-=1
                    while j<k and nums[j]==nums[j-1]:
                        j+=1 
                    while j<k and nums[k]==nums[k+1]: 
                        k-=1
                elif curr_sum>0: 
                    k-=1 
                else: 
                    j+=1
        return res