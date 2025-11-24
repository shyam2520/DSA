/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool> dict;
        ListNode* node=head;
        while(node && !dict.count(node)){
            dict[node]=true;
            node=node->next;
        } 
        return node;
    }
};