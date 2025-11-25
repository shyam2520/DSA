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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // unordered_map<ListNode*,bool> dict;
        ListNode* head=headA;
        while(headA){
            headA->val=-abs(headA->val);
            headA=headA->next;
        }

        while(headB){
            if(headB->val<0) {
                headB->val=abs(headB->val);
                break;
            }
            headB=headB->next;
        }

        while(head){
            head->val=abs(head->val);
            head=head->next;
        }
        return headB;
    }
};