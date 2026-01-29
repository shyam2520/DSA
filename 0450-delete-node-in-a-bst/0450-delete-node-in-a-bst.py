# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def searchDel(self,parent,node,key): 
        if node is None: 
            return None 
        if node.val == key: 
            rst=node.right
            lst=node.left
            prev,inorders = node.right,node.right 
            if inorders is None: 
                return lst
            while inorders.left:
                prev=inorders
                inorders=inorders.left 
            if prev is not inorders:
                prev.left = inorders.right 
            if rst is not inorders:
                inorders.right = rst 
            if lst is not inorders:
                inorders.left = lst
            return inorders 
        if node.val>key: 
            node.left=self.searchDel(node,node.left,key)
        else:
            node.right=self.searchDel(node,node.right,key)
        return node

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        # find the node 
        # find inorder successor 
        # if IS has a right child prev -> left = right childe 
        # that will be swapp
        dummy = TreeNode(-1) 
        dummy.right=self.searchDel(dummy,root,key)
        return dummy.right