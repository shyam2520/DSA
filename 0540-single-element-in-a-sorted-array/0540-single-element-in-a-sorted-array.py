class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1 
        while(l<=r): 
            mid=l+(r-l)//2 
            left_val =  float("-inf") if mid-1<0 else nums[mid-1]
            right_val = float("-inf") if mid+1>=len(nums) else nums[mid+1]
            if nums[mid]!=left_val and nums[mid]!=right_val: 
                return nums[mid]
            if nums[mid]==right_val:
                size = r-(mid+1)
                if size%2: 
                    l=mid+2 
                else:
                    r=mid-1 
            else: 
                size = mid-1 
                if size%2: 
                    r=mid-2 
                else:
                    l=mid+1
        
        return -1