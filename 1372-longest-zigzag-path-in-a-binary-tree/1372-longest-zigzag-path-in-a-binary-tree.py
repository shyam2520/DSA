# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res = 0
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.postorder(root,'-')
        return self.res

    def postorder(self,root,dir)->int:
        if root is None: 
            return 0 
        l = self.postorder(root.left,'l')
        r = self.postorder(root.right,'r')
        self.res=max(l,r,self.res)
        if dir=='l':
            return 1+r 
        return 1+l