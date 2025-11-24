/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* fast=head->next?head->next->next:head->next;
        ListNode* slow=head;
        while(fast && slow!=fast){
            slow=slow->next;
            fast=fast->next?fast->next->next:fast->next;
        }
        return slow==fast;
    }
};