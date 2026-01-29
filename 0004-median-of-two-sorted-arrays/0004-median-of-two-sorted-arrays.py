class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # creater a barrier for m+n//2 elements 
        # at each point compare the two elements with cross data 
        # if true then that would be median if not move accoridngly 
        # to optmize we do bin search on smaller value 
        
        m,n = len(nums1),len(nums2) 
        if m>n: 
            return self.findMedianSortedArrays(nums2,nums1)
        k = (m+n+1)//2
        l,r = 0,m 
        while l<=r: 
            mid1 = l+(r-l)//2 # elements from m  
            mid2 = k-mid1 # elements from n 
            nums1l = nums1[mid1-1] if mid1>0 else float("-inf")
            nums2l = nums2[mid2-1] if mid2>0 else float("-inf")
            nums1r = nums1[mid1] if mid1<m else float("inf")
            nums2r = nums2[mid2] if mid2<n else float("inf")
            if nums1l>nums2r: 
                r=mid1-1 
            elif nums2l>nums1r:
                l=mid1+1 
            else: 
                if (m+n)%2: 
                    return max(nums1l,nums2l)
                else: 
                    return (max(nums1l,nums2l)+min(nums1r,nums2r))/2

        return -1 