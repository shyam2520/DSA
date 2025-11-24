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
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            stack.push(slow->val);
            slow=slow->next;
            fast=fast->next?fast->next->next:fast->next;
        }   
        if(fast) slow=slow->next; // odd list 
        while(slow && stack.top()==slow->val){
            slow=slow->next;
            stack.pop();
        }
        return stack.empty();
    }
};