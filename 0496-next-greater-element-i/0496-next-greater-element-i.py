from collections import defaultdict

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        freq=defaultdict(int)
        st = [] 
        for i in range(len(nums2)): 
            while st and nums2[st[-1]]<nums2[i]:
                val,idx = nums2[st[-1]],st[-1] 
                st.pop() 
                # print(val,idx)
                freq[val]=nums2[i] 
            st.append(i)    
        res = []
        for val in nums1: 
            if val in freq:
                res.append(freq[val])
            else: 
                res.append(-1)
        return res