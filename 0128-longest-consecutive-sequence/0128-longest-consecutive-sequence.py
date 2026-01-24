class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        set_nums = set(nums)
        if len(set_nums)==0: 
            return 0
        cnt,res=1,1
        for x in set_nums: 
            val = x
            cnt = 0 
            if (val-1) in set_nums: 
                continue 
            else: 
                while val in set_nums:
                    cnt+=1 
                    # set_nums.remove(val) 
                    val+=1 
            res=max([res,cnt])
        return res