# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def dfs(self,node,res) -> int: 
        if node is None: 
            return 0 
        lst = self.dfs(node.left,res)
        rst = self.dfs(node.right,res)
        res[0] = max(res[0],lst+rst)
        return 1+max(lst,rst)
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int: 
        # get heigh of lst and rst 
        # at each point max(res,lst+rst) 
        # return max(lst,rst)
        res = [0]
        self.dfs(root,res)
        return res[0]