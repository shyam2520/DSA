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
        if(!head) return head;
        Node* node=head;
        while(node){
          Node* copy = new Node(node->val);
          Node* next = node->next;
          node->next = copy;
          copy->next = next;  
          node=next;
        }
        node=head;
        Node* cphead=node->next;
        while(node){
            Node* copy=node->next;
  
            Node* cprand=node->random?node->random->next:NULL;
            copy->random=cprand;
            // node->next=ognext;
            node=copy->next;
        }

        node=head;
        while(node){
            Node* copy=node->next;
            // Node* ognext=node->next?node->next->next:NULL;
            Node* ognext=copy?node->next->next:NULL;
            copy->next=ognext?ognext->next:NULL;
            node->next=ognext;
            node=ognext;
        }

        return cphead;
    }
};