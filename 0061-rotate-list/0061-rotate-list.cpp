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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=0;
        ListNode* node=head,*prev=NULL;
        while(node){
            prev=node;
            node=node->next;
            len++;
        }

        int cnt=len-(k%len);
        node=head;
        if(cnt==len) return head;
        while(node && --cnt){
            node=node->next;
        }
        ListNode *newhead=node->next;
        node->next=NULL;
        prev->next=head;
        return newhead;
    }
};