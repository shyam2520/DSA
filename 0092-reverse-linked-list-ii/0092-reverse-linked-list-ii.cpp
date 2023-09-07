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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* s=NULL,*e=NULL,*ps=NULL,*node=head,*prev=NULL;
        int count=1;
        while(node){
            if(count==left){
                ps=prev;
                s=node;
            }
            if(count==right) e=node;
            prev=node;
            node=node->next;
            count++;
        }
        ListNode* ne=e->next,*temp=NULL;
        prev=NULL;
        node=s;
        int itrs=right-left;
        // while(node!=e){
        //     cout<<node->val;
        //     node=node->next;
        // }
        // cout<<node->val;
        node=s;
        while(itrs>=0)
        {
            temp=node->next;
            node->next=prev;
            // cout<<node->val<<endl;
            prev=node;
            node=temp;
            itrs--;

        }
        s->next=ne;
        if(ps){
            ps->next=e;
        }
        else head=e;

        return head;

    }
};