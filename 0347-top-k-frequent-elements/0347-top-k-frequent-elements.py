from collections import defaultdict
from heapq import heappush,heappop

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        for val in nums: 
            freq[val]+=1 
        min_heap = []
        for key,fr in freq.items(): 
            heappush(min_heap,(fr,key))
            if len(min_heap)>k: 
                heappop(min_heap)
        res = []
        while min_heap:
            res.append(heappop(min_heap)[1])
        return res