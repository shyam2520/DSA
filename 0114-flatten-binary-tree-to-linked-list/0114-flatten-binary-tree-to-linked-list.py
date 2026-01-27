# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self): 
        self.prev=None
    
    def dfs(self,node): 
        if node is None: 
            return 
        
        rst = node.right
        self.prev.right=node
        self.prev=node 
        self.dfs(node.left)
        node.left=None
        self.dfs(rst) 
        

    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        dummy = TreeNode(-1) 
        self.prev = dummy 
        self.dfs(root)
        return dummy.right
        
        