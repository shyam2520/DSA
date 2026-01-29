from collections import defaultdict
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        # sliding window dict size <=2 that time reduce the anchor ptr 
        if k==0: 
            return 0 
        anc = 0 
        freq = defaultdict(int)
        ans = 0
        for i in range(len(s)): 
            freq[s[i]]+=1 
            while anc<i and len(freq)>k:
                freq[s[anc]]-=1 
                if freq[s[anc]]==0: 
                    del freq[s[anc]]
                anc+=1 
            ans = max(ans,i-anc+1) 
        return ans 
