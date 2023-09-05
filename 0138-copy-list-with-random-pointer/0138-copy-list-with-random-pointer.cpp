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
        unordered_map<Node*,Node*> dict;
        Node* first=head,*prev=NULL;
        while(head){
            if(dict.find(head)==dict.end()){
                dict[head]=new Node(head->val);
            }
            Node* copy=dict[head];
            if(prev) prev->next=copy;
            if(head->random && dict.find(head->random)==dict.end()){
                dict[head->random]=new Node(head->random->val);
            }
            copy->random=!head->random?head->random:dict[head->random];
            prev=copy;
            head=head->next;

        }
    return dict[first];
        
    }
};