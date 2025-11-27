/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *node=head;
        unordered_map<Node*,Node*> dict;
        Node *curr,*nextnode,*random;
        while(node){
            if(!dict.count(node)) dict[node]=new Node(node->val);
            if(node->next && !dict.count(node->next)) dict[node->next]=new Node(node->next->val);
            if(node->random && !dict.count(node->random)) dict[node->random] = new Node(node->random->val);

            curr=dict[node];
            random=dict[node->random];
            nextnode=dict[node->next];
            curr->next=nextnode;
            curr->random=random;

            node=node->next;
        }
        return dict[head];
    }
};