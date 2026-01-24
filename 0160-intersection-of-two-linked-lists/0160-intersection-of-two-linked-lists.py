# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        l1,l2 = headA,headB
        hAcpy,hBcpy = headA,headB 
        while l1 and l2 and l1!=l2: 
            l1=l1.next 
            l2=l2.next 
            if l1==None: 
                l1=hBcpy 
                hBcpy = None 
            if l2==None: 
                l2=hAcpy 
                hAcpy = None 
        
        return l1 