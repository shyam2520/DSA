class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals[:]=sorted(intervals,key=lambda x:x[0])
        res = []
        for interval in intervals: 
            if not(len(res)): 
                res.append(interval)
            else: 
                prev = res[-1] 
                if prev[1]>=interval[0]:
                    res.pop() 
                    new_st = min([prev[0],interval[0]])
                    new_end = max([prev[1],interval[1]])
                    res.append([new_st,new_end])
                else: 
                    res.append(interval)
        
        return res