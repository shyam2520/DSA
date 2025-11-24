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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow=head,*fast=head,*prev=NULL,*next=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next?fast->next->next:fast->next;
        }   
        prev->next=NULL;
        if(fast) slow=slow->next; // odd list 
        prev=NULL;
        while(slow){
            next = slow->next;
            slow->next = prev;
            prev=slow;
            slow=next;
        }

        while(head && prev && head->val==prev->val){
            head=head->next;
            prev=prev->next;
        }
        return !head && !prev;
    }
};