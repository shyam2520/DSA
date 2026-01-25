from collections import deque,defaultdict
from heapq import heappush,heappop,heapify
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # max heap which would only fot cnt to process high count 
        # queue -> (time,cnt) so that it can pushed into q if hitting the interval
        q=deque()
        freq = defaultdict(int)
        timer = 1 
        for val in tasks: freq[val]+=1
        pq = [] # max heap 
        for ch,cnt in freq.items(): 
            heappush(pq,-cnt) 
        timer = 1
        while pq or q: 
            if q and q[0][0]<=timer:
                time,cnt = q[0]
                q.popleft()
                # print(cnt)
                heappush(pq,-cnt)
            if pq:
                topcnt = abs(heappop(pq))
                if topcnt-1>0:
                    q.append((timer+n+1,topcnt-1))
            if pq or q: 
                timer+=1

        return timer
        
