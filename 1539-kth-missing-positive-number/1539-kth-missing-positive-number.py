class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        # 1. for given val - act_idx - curr_idx = missing_elements 
        # 2. find the lower bound idx for k missing ele 
        # 3. from there add remaining elemnts to get the answer 
        l,r=0,len(arr)-1 
        res = -1 
        if arr[0]-1>=k: 
            return k 
        while l<=r: 
            mid=l+(r-l)//2 
            aidx = arr[mid]-1 
            mele = aidx - mid
            if mele<k: 
                res=mid
                l=mid+1
            else: 
                r=mid-1 
        rem_ele = k-(arr[res]-1-res)
        return arr[res]+rem_ele
        
        