class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        # n = len(numRows)
        if numRows==1: return [[1]]
        if numRows==2: return [[1],[1,1]]
        res = [[1],[1,1]]
        for row in range(2,numRows):
            temp = [1]
            # update list 
            for col in range(1,row):
                val = res[row-1][col-1]+res[row-1][col]
                temp.append(val)
            temp.append(1)
            res.append(temp)
        return res