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
        unordered_map<ListNode*,bool> dict;
        while(headA){
            dict[headA]=true;
            headA=headA->next;
        }

        while(headB){
            if(dict.count(headB)) return headB;
            headB=headB->next;
        }

        return NULL;
    }
};