class Solution:

    def binsearch(self,nums,l,r,target): 
        while l<=r: 
            mid = l+(r-l)//2 
            if nums[mid]==target: 
                return mid 
            elif nums[mid]>target: 
                r=mid-1 
            else: 
                l=mid+1 
        return -1 

    def search(self, nums: List[int], target: int) -> int:
        l,r = 0,len(nums)-1 

        peak=-1 
        while l<=r: 
            mid = l+(r-l)//2 
            if nums[mid]>nums[-1]: 
                peak=mid
                l=mid+1 
            else: 
                r=mid-1 

        if peak==-1: 
            return self.binsearch(nums,0,len(nums)-1,target) 
        if nums[0]<=target<=nums[peak]:
            return self.binsearch(nums,0,peak,target) 
        return self.binsearch(nums,peak+1,len(nums)-1,target)