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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(-1000);
        ListNode *node=head,*prev=dummy,*next=NULL;
        dummy->next=node;
        int cnt=0;
        while(node){
            next=node->next;
            cnt=0;
            while(next && next->val==node->val){
                cnt++;
                next=next->next;
            }
            if(cnt) prev->next=next;
            else prev=node;
            node=next;
        }

        return dummy->next;
        
    }
};