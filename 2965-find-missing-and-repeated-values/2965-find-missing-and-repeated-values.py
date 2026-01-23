class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        m = len(grid)
        ans = []
        for row in range(m):
            for col in range(m): 
                val = abs(grid[row][col])-1
                ridx = val//m 
                cidx = val%m 
                if grid[ridx][cidx]<0: 
                    ans.append(val+1)
                else: 
                    grid[ridx][cidx]=-abs(grid[ridx][cidx])

        for ridx in range(m): 
            for jidx in range(m): 
                if grid[ridx][jidx]>0: 
                    ans.append(m*ridx + jidx+1)
        
        return ans