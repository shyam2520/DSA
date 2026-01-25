class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # m+n is even mean m+n/2 would be the barrier
        # if odd (m+n+1)/2 would be the barries 
        # so in that mean left of barrier of barrier elements in total 
        m,n = len(nums1),len(nums2) 
        k = 0 
        if m>n: 
            return self.findMedianSortedArrays(nums2,nums1)
        if (m+n)%2: 
            k=(m+n+1)//2
        else: 
            k=(m+n)//2
        
        # for range l,r in m we would mid element and nums 2  k-mid 
        # compare left and right for each value based on that we move the ptrs 
        l,r=0,m 
        while l<=r: 
            mid = l+(r-l)//2 
            nums1l = nums1[mid-1] if mid-1>=0 else float("-inf")
            nums2l = nums2[k-mid-1] if k-mid-1>=0  else float("-inf")
            nums1r = nums1[mid] if mid<m else float("inf")
            nums2r = nums2[k-mid] if k-mid<n else float("inf")
            if nums1l>nums2r: 
                r=mid-1
            elif nums2l>nums1r:
                l=mid+1
            else: 
                if (m+n)%2: 
                    return max(nums1l,nums2l)
                else: 
                    a = max(nums1l,nums2l)
                    b = min(nums2r,nums1r)
                    return (a+b)/2 
        return -1 
