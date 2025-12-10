class MyStack {
public:
    queue<int> q1,popq1;
    int top_val;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        top_val=x;
    }
    
    int pop() {
        while(q1.size()>1){
            popq1.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();

        while(popq1.size()){
            top_val=popq1.front();
            q1.push(top_val);
            popq1.pop();
        }
        return res;
    }
    
    int top() {
        return top_val;
    }
    
    bool empty() {
        return q1.size()==0;
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