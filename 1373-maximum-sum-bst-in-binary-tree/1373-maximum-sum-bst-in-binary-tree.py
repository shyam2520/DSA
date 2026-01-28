# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self): 
        self.res = 0 
    
    def postorder(self, node): 
        if node is None:
            return True,0,float("-inf"),float("inf") # sum,max,min 
        lvalid,suml,maxl,minl=self.postorder(node.left) 
        rvalid,sumr,maxr,minr=self.postorder(node.right)
        treesum = suml+sumr+node.val
        curr_valid = True 
        if lvalid and rvalid and maxl<node.val<minr: 
            self.res =max(self.res,treesum)
        else: 
            curr_valid = False 
        left = max(node.val,maxl,maxr)
        right = min(node.val,minl,minr) 
        return curr_valid,treesum,left,right

    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        # for each node compare left max and right min 
        # if valid then the current tree 
        # min = root,left min & max=root,right max , sum of everything  
        self.postorder(root) 
        return self.res