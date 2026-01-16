class Solution:
    
    
    def search(self, nums: List[int], target: int) -> int:
        def binsearch(l,r,nums,target):
            # res = -1
            while l<=r:
                mid = l+(r-l)//2 
                if nums[mid]==target: 
                    return mid
                if nums[mid]>target: 
                    r=mid-1 
                else: 
                    l=mid+1 
            return -1

        if len(nums)<2: 
            return 0 if nums[-1]==target else -1
        l,r=0,len(nums)-1
        res=-1
        while l<=r: 
            mid = l+(r-l)//2 
            if nums[mid]>nums[-1]: 
                res=mid
                l=mid+1 
            else: 
                r=mid-1
        
        if res ==-1:
            return binsearch(0,len(nums)-1,nums,target) 
        elif nums[0]<=target<=nums[res]: 
            return binsearch(0,res,nums,target)
        return binsearch(res+1,len(nums)-1,nums,target)