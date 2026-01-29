class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        zeros,ans,anc =0,0,0 
        for i,val in enumerate(nums): 
            if val==0: 
                zeros+=1
            while anc<=i and zeros>k: 
                if nums[anc]==0: 
                    zeros-=1 
                anc+=1 
            ans = max(ans,i-anc+1)
        return ans