# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def nextItr(self,st):
        top = st.pop() 
        node = top.right 
        while node : 
            st.append(node)
            node=node.left 
        return st 
    
    def prevItr(self,st): 
        top = st.pop() 
        node = top.left 
        while node: 
            st.append(node)
            node=node.right 
        return st 

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        left,right = [],[] 
        lptr,rptr = root,root

        while lptr: 
            left.append(lptr)
            lptr=lptr.left 
        
        while rptr: 
            right.append(rptr)
            rptr=rptr.right

        while left and right: 
            l,r = left[-1].val,right[-1].val
            if l+r==k and not(l is r): 
                return True 
            if l+r>k: 
                right=self.prevItr(right)
            else: 
                left=self.nextItr(left) 
        
        return False 