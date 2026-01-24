# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # find the mid point using slow,fast 
        # from the mid start reverse ll then you can traverse to check if not palindrom 
        slow,fast = head,head 
        while fast: 
            slow = slow.next 
            fast = fast.next.next if fast.next else fast.next 

        prev,curr,nextnode = None,slow,None   
        while curr : 
            nextnode = curr.next 
            curr.next = prev 
            prev = curr 
            curr=nextnode 
        
        l,r = head,prev 
        while l and r: 
            if l.val!=r.val:
                return False 
            l=l.next
            r=r.next 

        return True 

        