# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not(head): 
            return head
        cnt = 0 
        node = head 
        while node: 
            cnt+=1 
            node = node.next 

        k= k%cnt if k>=cnt else k 
        if k==0: 
            return head 
        l1,l2=head,head
    
        while l2.next : 
            k-=1
            if k<0: 
                l1=l1.next 
            l2=l2.next 

        l2.next = head 
        newhead = l1.next 
        l1.next = None 
        return newhead 
    