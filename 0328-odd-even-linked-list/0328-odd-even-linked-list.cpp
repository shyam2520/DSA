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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        int cnt=0;
        ListNode *node=head,*next=NULL;
        ListNode *oddHead=NULL,*evenHead=NULL;
        ListNode *oddTail=NULL,*evenTail=NULL;
        while(node){
            ++cnt;
            if(cnt%2){
                if(!oddHead) oddHead=node;
                oddTail=node;
            }
            else{
                if(!evenHead) evenHead=node;
                evenTail=node;
            }

            next=node->next;
            node->next=next?next->next:next;
            node=next;
        }

        oddTail->next=evenHead;
        evenTail->next=NULL;
        return oddHead;
    }
};