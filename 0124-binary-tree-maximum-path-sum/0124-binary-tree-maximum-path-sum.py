# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def dfs(self,node,res):
        if node is None: 
            return float("-inf") 
        lst = self.dfs(node.left,res)
        rst = self.dfs(node.right,res)
        curr = node.val 
        res[0]=max(res[0],lst,rst,node.val+lst,node.val,node.val+rst,node.val+lst+rst)
        return max(node.val+lst,node.val+rst,node.val)



    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res = [-10000000]
        self.dfs(root,res)
        return res[-1]