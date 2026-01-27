# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None: 
            return None 
        if root is p or root is q:
            return root 

        lst = self.lowestCommonAncestor(root.left,p,q)
        rst = self.lowestCommonAncestor(root.right,p,q)
        
        if lst and (rst is None): 
            return lst 
        if rst and (lst is None): 
            return rst 
        if lst and rst:
            return root
        return None