# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head
        if not(head) or not(head.next): 
            return head
        while slow and fast: 
            slow = slow.next 
            fast = fast.next.next if fast.next else fast.next 
            if not(fast) or not(fast.next): 
                return slow 
        return slow