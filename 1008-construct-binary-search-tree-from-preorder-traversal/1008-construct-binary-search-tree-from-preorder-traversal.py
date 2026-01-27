# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self): 
        self.preidx = 0 
    

    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        # each node gets pushed into stack if less than top 
        # if greater pop till you find the next greater
        # it would be right node of prev 
        # if st empty then the prev val only regardlles 
        # first val is root 
        st=[] 
        root = TreeNode(preorder[0])
        st.append(root) 
        for i in range(1,len(preorder)): 
            currnode = TreeNode(preorder[i])
            if st and st[-1].val>currnode.val: 
                st[-1].left = currnode
                st.append(currnode) 
            else: 
                prev =None 
                while st and st[-1].val<currnode.val: 
                    prev=st.pop()
                prev.right = currnode
                st.append(currnode) 

        return root 