class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        # 10 - 1010
        # 7  - 0111
        res = start ^ goal 
        cnt = 0
        while(res):
            cnt+=res&1 
            res>>=1 
        return cnt 