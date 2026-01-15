from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n=len(nums)
        hash_map = defaultdict(int)
        hash_map[0]+=1
        res=0
        curr_sum = 0
        for i in range(len(nums)): 
            curr_sum+=nums[i]
            if curr_sum-k in hash_map: 
                res+=hash_map[curr_sum-k]
            hash_map[curr_sum]+=1 
        return res 
        
