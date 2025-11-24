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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return  reverse(NULL,head);
    }

    ListNode* reverse(ListNode* prev,ListNode* node){
        // if(!node) return node;
        ListNode* head=NULL;
        if(node->next) head=reverse(node,node->next);
        node->next=prev;

        return !head?node:head;
    }

};