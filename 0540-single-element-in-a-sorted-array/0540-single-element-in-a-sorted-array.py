class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        # get the mid 
        # if the compare with left and right if its not equal thats the resul 
        # if prev is same exclude that and get the cnt 
        l,r = 0,len(nums)-1 
        while l<=r: 
            mid=l+(r-l)//2 
            prevele = nums[mid-1] if mid-1>=0 else float("-inf")
            nextele = nums[mid+1] if mid+1<len(nums) else float("-inf")

            if nums[mid]!=prevele and nums[mid]!=nextele: 
                return nums[mid]
            
            leftcnt = mid-l
            leftcnt = leftcnt-1 if nums[mid]==prevele else leftcnt
            leftcnt = max(0,leftcnt)
            
            if leftcnt%2!=0:
                r = mid-2 if nums[mid]==prevele else mid -1 
            else: 
                l= mid+2 if nums[mid]==nextele else  mid+1 
            
        return -1 