class Solution:
    def lower_bound(self,nums,l,r,target):
        res = -1
        while l<=r: 
            mid=l+(r-l)//2 
            if nums[mid]>=target:
                if nums[mid]==target: 
                    res=mid
                r=mid-1
            else: 
                l=mid+1 
        return  res if nums[res]==target else -1 

    def upper_bound(self,nums,l,r,target):
        res = -1
        while l<=r: 
            mid=l+(r-l)//2 
            if nums[mid]<=target:
                if nums[mid]==target: 
                    res=mid
                l=mid+1
            else: 
                r=mid-1 
        return  res if nums[res]==target else -1 

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums :
            return [-1,-1]
        
        l,r,res=0,len(nums)-1,-1 
        a = self.lower_bound(nums,l,r,target)
        b = self.upper_bound(nums,l,r,target)
        return [a,b]
        # while l<=r: 
        #     mid=l+(r-l)//2 
        #     if nums[mid]==target: 
        #         res=mid 
        #         break 
        #     if nums[mid]>target: 
        #         r=mid-1 
        #     else: 
        #         l=mid+1 
        # # if res==-1 : 
        #     return [-1,-1] 
        # if mid<len(nums)-1 and nums[res]==nums[res+1]: 
        #     return [res,res+1]
        # if mid>0 and nums[res]==nums[res-1]:
        #     return [res-1,res]
        # return [res,res]