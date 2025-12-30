class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stack;
        return recursion(s,0,stack);
    }
    
    bool recursion(string& s,int idx,stack<int> stack){
        if(idx==s.length()){
            return stack.empty();
        }
        if(s[idx]=='('){
            stack.push('(');
            return recursion(s,idx+1,stack);
        }
        if(s[idx]==')'){
            if(stack.size()&& stack.top()=='(') stack.pop();
            else stack.push(')');
            return recursion(s,idx+1,stack);
        }
        bool empty = recursion(s,idx+1,stack);
        stack.push('(');
        bool open = recursion(s,idx+1,stack);
        stack.pop();
        // stack.push(')');
        if(stack.size()&& stack.top()=='(') stack.pop();
        else stack.push(')');
        bool close = recursion(s,idx+1,stack);
        return empty||open||close;
    }

};