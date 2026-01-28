# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode, parent=None) -> Optional[TreeNode]:
        if not(root): 
            return root 
        if root.val==p.val: 
            root = root.right 
            while root and root.left: 
                root=root.left 
            return root if root else parent

        if root.val>p.val:
            return  self.inorderSuccessor(root.left,p,root)
        return self.inorderSuccessor(root.right,p,parent)
        