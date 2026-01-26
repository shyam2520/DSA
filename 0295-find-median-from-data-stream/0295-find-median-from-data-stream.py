from heapq import heapify,heappush,heappop 

class MedianFinder:

    def __init__(self):
        self.min_heap =[] # right half 
        self.max_heap =[] # left half

    def resetHeap(self,max_heap,min_heap): 
        # we push max_heap 
        # if total is even -> ensure both heaps are same size 
        # if total is odd -> ensure size(max_heap)-size(min_heap)==1
        total = len(max_heap) + len(min_heap)
        if total%2: 
            # ensure max_heap > 1 min_heap in size 
            while len(max_heap)!=1+len(min_heap):
                if len(max_heap)>len(min_heap):
                    heappush(min_heap,abs(heappop(max_heap)))
                else: 
                    heappush(max_heap,-heappop(min_heap))
        else: 
            while len(max_heap)!=len(min_heap): 
                if len(max_heap)>len(min_heap):
                    heappush(min_heap,-(heappop(max_heap)))
                else: 
                    heappush(max_heap,-heappop(min_heap))


    def addNum(self, num: int) -> None:
        # place the value in correct heap
        if len(self.min_heap) and self.min_heap[0]<num:
            heappush(self.min_heap,num) 
        elif len(self.max_heap) and -(self.max_heap[0])>num:
            heappush(self.max_heap,-num)
        else: 
            heappush(self.max_heap,-num)

        self.resetHeap(max_heap=self.max_heap,min_heap=self.min_heap)

    def findMedian(self) -> float:
        total = len(self.min_heap)+len(self.max_heap) 
        if total%2: 
            return -(self.max_heap[0])
        else:
            return (-self.max_heap[0]+self.min_heap[0])/2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()