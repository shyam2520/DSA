class Solution:
    def __init__(self): 
        self.res = 0 

    def merge(self,left,right): 
        l1s,l2s=len(left),len(right) 
        new_arr=[]
        i,j=0,0
        tidx=-1
        while i<l1s and j<l2s: 
            if left[i]>=right[j]: 
                # check for pair 
                if tidx==-1: 
                    tidx = i 
                while tidx<l1s and left[tidx]<=2*right[j]: 
                    tidx+=1
                self.res+=l1s-tidx
                new_arr.append(right[j])
                j+=1
            else: 
                new_arr.append(left[i])
                i+=1 

        while i<l1s: 
            new_arr.append(left[i])
            i+=1

        while j<l2s: 
            new_arr.append(right[j])
            j+=1 
        # new_arr.reverse()
        return new_arr 

    def mergeSort(self,arr,l,r): 
        if l==r: 
            return [arr[l]]
        mid = l+(r-l)//2 
        left = self.mergeSort(arr,l,mid)
        right = self.mergeSort(arr,mid+1,r) 
        new_arr = self.merge(left,right) 
        return new_arr     

    def reversePairs(self, nums: List[int]) -> int:
        # merge sort 
        # during merge keep a count of total pair 
        self.mergeSort(nums,0,len(nums)-1)
        return self.res