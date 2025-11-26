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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node=head;
        int len=0;
        while(node){
            len++;
            node=node->next;
        }
        return reverseList(head,len,k);

    }

    ListNode* reverseList(ListNode *head,int len,int k){
        if(k>len || !head || !head->next) return head;
        ListNode *dummy=new ListNode(-1);
        int cnt=k;
        dummy->next=head;

        ListNode *prev=dummy,*next=NULL,*node=head;
        while(cnt--){
            next=node->next;
            node->next=prev;
            prev=node;
            node=next;
        }

        dummy->next->next=reverseList(next,len-k,k);
        return prev;
    }
};