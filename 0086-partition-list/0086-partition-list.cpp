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
    void setPointers(ListNode*&  s,ListNode*& fs,ListNode*& head){
        // cout<<head->val<<endl;
        if(!s){
            s=head;
            fs=s;    
        } 
        else{
            s->next=head;
            s=s->next;
        }
        // s=head;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* s=NULL,*fs=NULL,*b=NULL,*fb=NULL;
        // cout<<s->val<<endl;
        while(head){
            // cout<<head->val<<endl;
            if(head->val<x) setPointers(s,fs,head);
            else setPointers(b,fb,head);
            head=head->next;
        }
        if(s) s->next=fb;
        if(b) b->next=NULL;
        return fs?fs:fb;
    }
};