class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m,n=len(matrix),len(matrix[0])
        top,down=0,m-1 
        left,right=0,n-1 
        res = []
        while top<=down and left<=right: 
            for i in range(left,right+1): 
                res.append(matrix[top][i])
            top+=1 
            if(top>down): break

            for i in range(top,down+1): 
                res.append(matrix[i][right])
            
            right-=1
            if(left>right): break

            for i in range(right,left-1,-1):
                res.append(matrix[down][i])

            down-=1 
            if(top>down): break 
            for i in range(down,top-1,-1): 
                res.append(matrix[i][left])
            left+=1
    
        return res