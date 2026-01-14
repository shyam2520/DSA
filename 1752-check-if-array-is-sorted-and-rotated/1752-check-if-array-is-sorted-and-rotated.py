class Solution:
    def check(self, nums: List[int]) -> bool:
        
        n = len(nums)
        for i in range(1,n+1): 
            if i==n or nums[i]<nums[i-1]: 
                break 
        
        if i==n: 
            return True  
        
        # iterator 
        j = i+1
        while j%n!=i:
            curr = int(j%n) 
            prev = int((j-1)%n)
            if nums[curr]<nums[prev]: 
                return False
            j+=1 

        return True 
        