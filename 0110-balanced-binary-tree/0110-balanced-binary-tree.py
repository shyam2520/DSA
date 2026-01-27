# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self): 
        self.res = True 

    def dfs(self,node): 
        if node is None: 
            return 0 
        lst = self.dfs(node.left) 
        rst = self.dfs(node.right)
        if abs(lst-rst)>1: 
            self.res=False 
        return 1+max(lst,rst) 

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None: 
            return True 
        self.dfs(root)
        return self.res
        