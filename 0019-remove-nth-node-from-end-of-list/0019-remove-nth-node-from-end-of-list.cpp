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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev=NULL,*slow=head,*fast=head;
        int cnt=0;
        while(fast->next){
            if(++cnt>=n){
                prev=slow;
                slow=slow->next;
            } 
            fast=fast->next;
        }
        if(prev==NULL) return slow->next;
        prev->next=slow->next;
        // slow->next=slow->next->next;
        return head;
    }
};