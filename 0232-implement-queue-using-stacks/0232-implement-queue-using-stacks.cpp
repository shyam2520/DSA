class MyQueue {
public:
    stack<int> a,b;
    int top;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(a.empty()) top=x;
        a.push(x);
    }
    
    int pop() {
        while(a.size()){
            b.push(a.top());
            a.pop();
        }
        int res = b.top();
        b.pop();
        top=b.size()?b.top():-1;
        while(b.size()){
            a.push(b.top());
            b.pop();
        }
        return res;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return a.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */