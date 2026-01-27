# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def dfs(self,node,coord,ridx,nodemap): 
        if node is None: 
            return 
        
        if ridx in nodemap: 
            l,r = nodemap[ridx] 
            nodemap[ridx]=(min(l,coord),max(r,coord))
        else: 
            nodemap[ridx]=(coord,coord)
        
        self.dfs(node.left,2*coord,ridx+1,nodemap) 
        self.dfs(node.right,2*coord+1,ridx+1,nodemap)


    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        nodemap = {} 
        self.dfs(root,1,1,nodemap)
        res = 0 
        for k,coords in nodemap.items(): 
            l,r=coords 
            res = max(res,r-l+1)
        return res 