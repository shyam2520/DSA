class DLLNode{
    public: 
    int key,val;
    DLLNode *next,*prev;

    DLLNode(int key,int value){
        this->key=key;
        this->val=value;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
public:
    DLLNode *head=new DLLNode(-1,-1);
    DLLNode *tail=new DLLNode(-1,-1);
    int cap;
    unordered_map<int,DLLNode*> dict;

    LRUCache(int capacity) {
        this->cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(DLLNode *node){
        DLLNode *prevNode = node->prev;
        DLLNode *nextNode = node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insertAfterHead(DLLNode *node){
        DLLNode *headNext = head->next; 
        head->next=node;
        node->prev=head;
        node->next=headNext;
        headNext->prev=node;
    }

    int get(int key) {
        // return 0;
        if(dict.count(key)){
            DLLNode *node=dict[key];
            deleteNode(node);
            insertAfterHead(node);
            return dict[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!dict.count(key)){
            DLLNode *node = new DLLNode(key,value);
            insertAfterHead(node);
            dict[key]=node;
        }
        else{
            DLLNode* node = dict[key];
            deleteNode(node);
            insertAfterHead(node);
            node->val=value;
        }
        if(dict.size()>cap){
            DLLNode *node = tail->prev;
            dict.erase(node->key);
            deleteNode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */