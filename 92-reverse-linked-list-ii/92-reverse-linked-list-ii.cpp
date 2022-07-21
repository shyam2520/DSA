/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int idx=1;
        ListNode* prev=NULL,*prevfirst=NULL,*first=NULL,*last=NULL;
        ListNode* node=head;
        while(node && (!first || !last))
        {
            if(idx==left)
            {
                prevfirst=prev;
                first=node;
            }
            else if(idx==right) last=node;
            prev=node;
            node=node->next;
            idx++;
        }
        ListNode* lastnext=last?last->next:last,*curr=first,*prrev=NULL,*next=curr->next;
        while(curr!=lastnext)
        {
            curr->next=prrev;
            prrev=curr;
            curr=next;
            next=curr?curr->next:curr;
        }
        first->next=lastnext;
        if(!prevfirst) return prev;
        prevfirst->next=prev;
        return head;
        
    }
};