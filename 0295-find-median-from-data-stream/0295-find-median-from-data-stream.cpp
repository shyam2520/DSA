class MedianFinder {
public:
    // min_heap for all n/2 (second half of the array)
    // max_heap for all n/2+1 element(first half);
    // if n is even -> min_heap+max_heap / 2 
    // if n is odd -> max_heap top element
    priority_queue<int,vector<int>,greater<int>> minh;
    priority_queue<int> maxh;
    int cnt;
    MedianFinder() {
        this->cnt=0;
    }
    
    void addNum(int num) {
        ++cnt;
        minh.push(num);
        if(cnt&1){
            maxh.push(minh.top());
            minh.pop();
        }
        if(cnt&1==0){
            while(minh.size()!=maxh.size()){
                if(minh.size()>maxh.size()){
                    maxh.push(minh.top());
                    minh.pop();
                }
                else{
                    minh.push(maxh.top());
                    maxh.pop();
                }
            }
        }
        else{
            while(maxh.size()<(cnt/2+1)){
                maxh.push(minh.top());
                minh.pop();
            }
            while(minh.size()<cnt/2){
                minh.push(maxh.top());
                maxh.pop();
            }

        }
    }
    
    double findMedian() {
        if(cnt&1) return (double)maxh.top();
        double ans = (double)minh.top()+(double)(maxh.top());
        return ans/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */