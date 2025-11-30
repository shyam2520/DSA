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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // pointer for l1,l2,l3;
        ListNode *l1=list1,*l2=list2,*dummy=new ListNode(-1);
        ListNode *l3=dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                l3->next=l1;
                l1=l1->next;
            }
            else{
                l3->next=l2;
                l2=l2->next;
            }
            l3=l3->next;
        }

        if(l1) l3->next=l1;
        if(l2) l3->next=l2;

        return dummy->next;
    }
};