class MinStack {
public:
    stack<int> stack,minstack;
    MinStack() {
        // stack - [-2,0,-3]
        // minstack - [-2,-3]
    }
    
    void push(int val) {
        // push into stack , push to minstack only if val<minstack.top();
        stack.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else if(minstack.size() && minstack.top()>=val){
            minstack.push(val);
        }
    }
    
    void pop() {
        int top_val=stack.top();
        if(minstack.top()==top_val){
            minstack.pop();
        }
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