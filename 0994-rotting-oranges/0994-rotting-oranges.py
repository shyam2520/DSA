from collections import deque 

class Solution:
    def __init__(self):
        self.dir=[(-1,0),(1,0),(0,1),(0,-1)]
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q=deque() 
        m,n=len(grid),len(grid[0])
        cnt=0
        for rowidx in range(m): 
            for colidx in range(n): 
                if grid[rowidx][colidx]==2: 
                    q.append((rowidx,colidx))
                if grid[rowidx][colidx]==1:
                    cnt+=1
        
        mins=0 
        while q: 
            qs = len(q) 
            for i in range(qs): 
                ridx,cidx = q.popleft()
                for x,y in self.dir: 
                    newx = ridx+x 
                    newy = cidx+y  
                    if newx<0 or newy<0 or newx==m or newy==n or grid[newx][newy]!=1: 
                        continue 
                    else: 
                        cnt-=1
                        q.append((newx,newy))
                        grid[newx][newy]=2
            if len(q): 
                mins+=1

        return mins if cnt==0 else -1
