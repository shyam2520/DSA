class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        key_cnt = {} 
        curr_sum = 0 
        key_cnt[0]=1
        total = 0
        for val in nums: 
            curr_sum+=val 
            if curr_sum-k in key_cnt: 
                total+=key_cnt[curr_sum-k]
            key_cnt[curr_sum]=key_cnt.get(curr_sum,0)+1

        return total 