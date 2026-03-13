class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        # champ = [[0.0 for _ in range(101)] for _ in range(101)]
        curr = [ 0.0 for _ in range(101)]
        next_row = [ 0.0 for _ in range(101)]

        # print(len(ans),len(ans[0]))
        curr[0]=poured
        for i in range(query_row+1):
            for j in range(0,i+1):
                glass = min(1,curr[j])
                rem = curr[j]-glass; 
                curr[j]=glass
                next_row[j]+=rem/2
                if j+1<len(next_row):
                    next_row[j+1]=rem/2 
            if i==query_row: 
                return curr[query_glass]
            curr=next_row
            next_row = [0]*101

        return -1