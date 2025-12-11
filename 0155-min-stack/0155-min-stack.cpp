class MinStack {
public:
    stack<int> stack,minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        if(minstack.empty()) minstack.push(val);
        else if(minstack.top()>=val) minstack.push(val);
    }
    
    void pop() {
        if(minstack.top()==stack.top()) minstack.pop();
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */