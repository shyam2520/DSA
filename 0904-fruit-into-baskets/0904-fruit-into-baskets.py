from collections import defaultdict 

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans,anc=0,0
        freq = defaultdict(int)
        for i in range(len(fruits)): 
            freq[fruits[i]]+=1 
            while anc<=i and len(freq)>2: 
                freq[fruits[anc]]-=1
                if freq[fruits[anc]]==0: 
                    del freq[fruits[anc]]
                anc+=1
            ans = max(ans,i-anc+1)

        return ans 