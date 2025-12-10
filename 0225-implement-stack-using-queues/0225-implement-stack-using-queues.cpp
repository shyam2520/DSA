class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(10);
        q.push(x);
        int top;
        while(q.front()!=10){
            top=q.front();
            q.pop();
            q.push(top);
        }
        q.pop();
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */