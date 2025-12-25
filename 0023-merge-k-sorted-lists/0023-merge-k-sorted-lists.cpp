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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        if(n==1) return lists.back();
        return mergesort(lists,0,n-1);
    }

    ListNode* merge(ListNode* l,ListNode* r){
        ListNode* dummy = new ListNode(-1);
        ListNode *node = dummy;
        while(l && r){
            if(l->val<r->val){
                node->next=l;
                l=l->next;
            }
            else{
                node->next=r;
                r=r->next;
            }
            node=node->next;
        } 
        if(l) node->next=l;
        if(r) node->next=r;
        return dummy->next;
    }
    ListNode* mergesort(vector<ListNode*>& lists,int s,int e){
        // if(s>e) return NULL;
        if(s==e) return lists[s];

        int mid = s+(e-s)/2;
        ListNode* l=mergesort(lists,s,mid);
        ListNode* r=mergesort(lists,mid + 1,e);

        return merge(l,r);
    }
};