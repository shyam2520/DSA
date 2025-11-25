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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *n1=l1,*n2=l2;
        ListNode *t1=n1;
        int carry=0,total=0;
        while(n1 && n2){
            total=n1->val+n2->val+carry;
            carry=total/10;
            n1->val=total%10;
            t1=n1;
            n1=n1->next;
            n2=n2->next;
        }
        while(n1){
            total=n1->val+carry;
            n1->val=total%10;
            carry=total/10;
            t1=n1;
            n1=n1->next;
        }

        while(n2){
            t1->next=n2;
            total=n2->val+carry;
            n2->val=total%10;
            carry=total/10;
            t1=n2;
            n2=n2->next;
        }

        if(carry) t1->next=new ListNode(carry);

        return l1;

    }
};