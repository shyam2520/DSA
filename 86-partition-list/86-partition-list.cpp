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
        ListNode node1(0),node2(0);
        ListNode* n1=&node1,*n2=&node2;
        ListNode* beg=n1,*beg2=n2;
        while(head)
        {
            if(head->val<x)
            {
                n1->next=head;
                n1=head;
            }
            else
            {
                n2->next=head;
                n2=head;
            }
            head=head->next;
        }
        
        n2->next=NULL;
        n1->next=beg2->next;
        return beg->next;
    
    }
};