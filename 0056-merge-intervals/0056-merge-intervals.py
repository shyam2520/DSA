class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals,key=lambda x:x[0])
        res = [intervals[0]] 
        for i in range(1,len(intervals)):
            curr=intervals[i] 
            prev=res[-1]
            if curr[0]<=prev[1]: 
                res.pop()
                res.append([min(curr[0],prev[0]),max(curr[1],prev[1])])
            else: 
                res.append(curr)
        return res 