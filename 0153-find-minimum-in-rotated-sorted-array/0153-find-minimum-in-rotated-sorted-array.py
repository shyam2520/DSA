class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r,peak = 0,len(nums)-1,-1
        while(l<=r): 
            mid = l+(r-l)//2 
            if nums[mid]>nums[-1]: 
                peak = mid
                l=mid+1
            else: 
                r=mid-1 

        if(peak==-1): 
            return nums[0] 
        else: 
            return nums[peak+1] 
        