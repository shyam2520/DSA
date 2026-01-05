class DLLNode{
    public: 
    int key,val;
    DLLNode *next,*prev;
    DLLNode(int key,int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LRUCache {
public:
    int cap;
    DLLNode *head,*tail;
    unordered_map<int, DLLNode*> umap;
    LRUCache(int capacity){
        this->cap = capacity;
        this->head = new DLLNode(-1,-1);
        this->tail = new DLLNode(-1,-1);
        this->head->next = tail;
        this->tail->prev = head;
    }
    
    void insertAfterHead(DLLNode* node){
        DLLNode *nextNode = head->next;
        node->prev = head;
        node->next = nextNode;
        head->next = node;
        nextNode->prev = node;
    }

    void deleteNode(DLLNode* node){
        DLLNode* prevNode = node->prev;
        DLLNode* nextNode = node->next; 
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        // delete(node);
    }

    int get(int key) {
        if(umap.find(key)==umap.end()) {
            return -1;
        }
        else{
            deleteNode(umap[key]);
            insertAfterHead(umap[key]);
            return umap[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(umap.find(key)==umap.end()){
            DLLNode *node = new DLLNode(key,value);
            insertAfterHead(node);
            umap[key]=node;
        }
        else{
            deleteNode(umap[key]);
            umap[key]->val = value;
            insertAfterHead(umap[key]);
        }
        if(umap.size()>cap){
            DLLNode *delNode = tail->prev;
            deleteNode(delNode);
            umap.erase(delNode->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */