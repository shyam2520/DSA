class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums[:] = sorted(nums) 
        n = len(nums)
        res=[]
        for i in range(len(nums)): 
            if i>0 and nums[i]==nums[i-1]: 
                continue 
            for j in range(i+1,len(nums)): 
                if j>i+1 and nums[j]==nums[j-1]:
                    continue 
                l,r=j+1,n-1
                while l<r: 
                    total = nums[i]+nums[j]+nums[l]+nums[r] 
                    if total>target: 
                        r-=1
                    elif total<target: 
                        l+=1 
                    else: 
                        res.append([nums[i],nums[j],nums[l],nums[r]])
                        l+=1
                        r-=1
                        while l<r and l>j+1 and nums[l]==nums[l-1]:
                            l+=1 
                        while l<r and r<n-1 and nums[r]==nums[r+1]:
                            r-=1
        
        return res
