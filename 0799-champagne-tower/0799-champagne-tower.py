class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        champ = [[0.0 for _ in range(101)] for _ in range(101)]
        # print(len(ans),len(ans[0]))
        champ[0][0]=poured
        for i in range(query_row+1):
            for j in range(0,i+1):
                glass = min(1,champ[i][j])
                rem = champ[i][j]-glass; 
                champ[i][j]=glass
                champ[i+1][j]+=rem/2
                if j+1<len(champ[0]):
                    champ[i+1][j+1]=rem/2 
             
        return champ[query_row][query_glass]