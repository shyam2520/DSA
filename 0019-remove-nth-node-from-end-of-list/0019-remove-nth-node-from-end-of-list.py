# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        l1,l2,prev = head,head,None 

        while l2.next: 
            l2=l2.next
            if n<=0:
                l1=l1.next 
            n-=1 
        
        if n>0:
            return head.next 
        l1.next =l1.next.next 
        return head

