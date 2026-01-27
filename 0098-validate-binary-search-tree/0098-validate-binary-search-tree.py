# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self,
        root: Optional[TreeNode],mini=None,
        maxi=None) -> bool:
        
        if root is None: 
            return True  
        if mini and maxi and (root.val<=mini.val or root.val>=maxi.val): 
            return False
        
        return self.isValidBST(root.left,mini,root) and self.isValidBST(root.right,root,maxi)
