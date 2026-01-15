class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n=len(nums) 
        # nums[:]=sorted(nums)
        nums.sort()
        res = []
        i,j,k,l=0,0,0,0 
        while i<n: 
            #duplicates 
            while i>0 and i<n and nums[i]==nums[i-1]: 
                i+=1 
            
            j=i+1
            while j<n:
                #duplicates
                while j>i+1 and j<n and nums[j]==nums[j-1]: 
                    j+=1 
                
                k,l=j+1,n-1
                while k<l: 
                    curr_sum = nums[i]+nums[j]+nums[k]+nums[l] 
                    if(curr_sum==target): 
                        res.append([nums[i],nums[j],nums[k],nums[l]])
                        k+=1
                        l-=1 
                        while k<l and nums[k]==nums[k-1]: 
                            k+=1
                        while k<l and nums[l]==nums[l+1]: 
                            l-=1  
                    elif(curr_sum>target): 
                        l-=1
                    else: 
                        k+=1 
                j+=1
            i+=1
        
        return res
