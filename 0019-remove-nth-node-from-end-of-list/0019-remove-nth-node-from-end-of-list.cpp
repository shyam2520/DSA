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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 2 pointer at distance n
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        int cnt = 0;
        while(fast){
            cnt++;
            if(cnt>n+1) slow = slow->next;
            fast=fast->next;
        }
        ListNode * nextNode = slow->next;
        slow->next = nextNode?nextNode->next:NULL;
        return dummy->next;
    }
};