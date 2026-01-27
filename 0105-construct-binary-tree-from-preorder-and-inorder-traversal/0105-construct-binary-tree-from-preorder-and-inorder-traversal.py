# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self): 
        self.preidx = 0

    def findNode(self,inorder,l,r,target): 
        for i in range(l,r+1): 
            if inorder[i]==target:
                return i 
        
        return -1 

    def constructTree(self,preorder,inorder,l,r): 
        if l==r: 
            self.preidx+=1
            return TreeNode(inorder[l])
        if l>r: 
            return None
        inidx = self.findNode(inorder,l,r,preorder[self.preidx])
        if inidx==-1: return None 
        currnode = TreeNode(preorder[self.preidx])
        self.preidx+=1 
        currnode.left = self.constructTree(preorder,inorder,l,inidx-1) 
        currnode.right = self.constructTree(preorder,inorder,inidx+1,r)
        return currnode 

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        m = len(inorder)-1
        return self.constructTree(preorder,inorder,0,m)
        
        