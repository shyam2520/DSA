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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<ListNode*> list;
        while(head){
            list.push_back(head);
            head=head->next;
        }
        sort(begin(list),end(list),[](ListNode* a,ListNode* b){
            return a->val<b->val;
        });

        for(int i=0;i<list.size()-1;i++){
            list[i]->next=list[i+1];
        }
        list.back()->next=NULL;
        return list.front();
    }
};