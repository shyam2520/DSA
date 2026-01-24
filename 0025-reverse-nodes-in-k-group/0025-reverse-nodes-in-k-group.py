# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def recursion(self,front,k,n):
        if front==None or n<k: 
            return front 
        curr_node,prev,nextNode,firstcpy = front,None,None,front
        cnt = 0
        while curr_node and cnt!=k:
            nextNode = curr_node.next 
            curr_node.next = prev
            prev=curr_node
            curr_node = nextNode
            cnt+=1
        firstcpy.next = self.recursion(nextNode,k,n-cnt)
        return prev

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # in function reverse node upto 
        # head->next = recursive(nextNode)
        # return lastNode reverse 
        cnt = 0 
        node = head 
        while node: 
            node = node.next 
            cnt+=1 
        return self.recursion(head,k,cnt)