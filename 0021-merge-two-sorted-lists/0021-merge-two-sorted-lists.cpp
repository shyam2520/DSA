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
        // l1,l2,l3 
        //  compare l1 with l2 and set l3 ptr accordingly 
        //  if either ptr exhausts then connect remaining list and return 
        ListNode* l1=list1,*l2=list2;
        ListNode* l3 = new ListNode(-1);
        ListNode* l3head=l3;
        while(l1 && l2){
            if(l1->val<=l2->val){
                l3->next = l1;
                l1=l1->next;
            }
            else{
                l3->next = l2;
                l2=l2->next;
            }
            l3=l3->next;
        }
        if(!l1 && l2) l3->next = l2;
        if(!l2 && l1) l3->next = l1; 

        return l3head->next;
    }
};