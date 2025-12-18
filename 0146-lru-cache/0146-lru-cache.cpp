class LRUCache {
public:
    int qsize=0;
    int cap;
    queue<int> q;
    unordered_map<int,int> dict,qdict;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(dict.count(key)){
            qdict[key]++;
            q.push(key);
            return dict[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!dict.count(key)){
            dict[key]=value;
            q.push(key);
            qsize++;
            qdict[key]++;
        }
        else{
            dict[key]=value;
            q.push(key);
            qdict[key]++;
        }
        while(qsize>cap){
            qdict[q.front()]--;
            if(!qdict[q.front()]){
                dict.erase(q.front());
                qsize--;
            }
            q.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */