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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *l1=new ListNode(-1);
        ListNode *l2=new ListNode(-1);
        // ListNode *l3=new ListNode(-1);
        ListNode *l1h=l1,*l2h=l2;
        // l1<x,l2>x, l3=x
        while(head){
            if(head->val<x){
                l1->next=head;
                l1=l1->next;
            }
            else if((head->val)>=x){
                l2->next=head;
                l2=l2->next;
            }
            // else{
            //     l3->next=head;
            //     l3=l3->next;
            // }
            head=head->next;
        }
        if(l2) l2->next=NULL;
        if(l1) l1->next=NULL;
        l1->next=l2h->next;
        return l1h->next;
    }
};