from collections import defaultdict,Counter 
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dicts=Counter(s)
        dictt=Counter(t)
        return dicts==dictt
        