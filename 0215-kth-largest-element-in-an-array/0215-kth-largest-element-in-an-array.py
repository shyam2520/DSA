from heapq import heappush,heappop 
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap =[] 
        for val in nums: 
            heappush(min_heap,val) 
            if len(min_heap)>k:
                heappop(min_heap)
        return min_heap[0]