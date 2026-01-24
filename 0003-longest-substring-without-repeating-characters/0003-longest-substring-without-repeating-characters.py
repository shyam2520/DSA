class Solution:
    def checkDup(self,freq)->bool: 
        for val in freq.values(): 
            if val>1: 
                return True 
        return False 
    def lengthOfLongestSubstring(self, s: str) -> int:
        anc,res = 0,0
        freq = {}
        for idx,val in enumerate(s): 
            freq[val]=freq.get(val,0)+1 
            while anc<idx and self.checkDup(freq): 
                freq[s[anc]]-=1 
                anc+=1 
            res = max([res,idx-anc+1])
        return res