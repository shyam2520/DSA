// Node
class Node {
public:
    int val, key, cnt;
    Node *prev, *next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->cnt = 1;
        this->prev = NULL;
        this->next = NULL;
    }
};

// DLL-> insertAfterHead, removeNode;
class List {
public:
    Node *head, *tail;
    int size;
    List() {
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        // cout<<this->head->key<<endl;÷
        this->head->next = tail;
        this->tail->prev = head;
        this->size = 0;
    }

    void insertAfterHead(Node* node,Node* head,Node* tail) {
        Node* headNext = head->next;
        node->next = headNext;
        headNext->prev = node;
        head->next = node;
        node->prev = head;
        this->size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        this->size--;
    }

};

// when udapting frequency of list minfreq gets update when list is empty

class LFUCache {
public:
    map<int, Node*> dict;
    map<int, List*> freqList;
    int currsize, cap, minFreq;

    LFUCache(int capacity) {
        this->currsize = 0;
        this->cap = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (!dict.count(key))
        {    return -1;}
        Node* node = dict[key];
        int nodeFreq = node->cnt;
        node->cnt += 1;
        List* nodeList = freqList[nodeFreq];
        nodeList->removeNode(node);
        if (nodeList->size == 0) {
            freqList.erase(nodeFreq);
            if (minFreq == nodeFreq)
            {    minFreq = node->cnt;}
        }
        // newFreqList
        List* newNodeList;
        if (freqList.count(node->cnt)) {
            newNodeList = freqList[node->cnt];
        }
        else{
            newNodeList = new List();
            freqList[node->cnt]=newNodeList;
        }
    
        newNodeList->insertAfterHead(node,newNodeList->head,newNodeList->tail);
        return node->val;
    }

    void put(int key, int value) {
        if(cap==0) return;
        // check if it is already at capacity if so delete first b4 insert
        if (!dict.count(key) && currsize == cap) {
            // remove tail node, remove dict refernce of the key
            List* nodeList = freqList[minFreq];
            Node* deleteNode = nodeList->tail->prev;
            nodeList->removeNode(deleteNode);
            dict.erase(deleteNode->key);
            currsize--;
            if (nodeList->size == 0) {
                freqList.erase(minFreq);
                minFreq++;
            }
        }

        if (!dict.count(key)) {
            Node* node = new Node(key,value);
            dict[key]=node;
            List* nodeList;
            if (freqList.count(1)) {
                nodeList = freqList[1];
            }
            else{
                nodeList = new List();
                freqList[1]=nodeList;
            }
            nodeList->insertAfterHead(node,nodeList->head,nodeList->tail);
            minFreq = 1;
            currsize++;
        } else {
            // key exists 1. udpate value 2. change the frequency list
            Node* node = dict[key];
            node->val = value;
            int nodeFreq = node->cnt;
            node->cnt += 1;
            List* nodeList = freqList[nodeFreq];
            nodeList->removeNode(node);
            if (nodeList->size == 0) {
                freqList.erase(nodeFreq);
                if (minFreq == nodeFreq)
                {    minFreq = node->cnt;}
            }
            // newFreqList
            List* newNodeList;
            if (freqList.count(node->cnt)) {
                newNodeList = freqList[node->cnt];
            }
            else{
                newNodeList = new List();
                freqList[node->cnt]=newNodeList;
            }
            newNodeList->insertAfterHead(node,newNodeList->head,newNodeList->tail);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */