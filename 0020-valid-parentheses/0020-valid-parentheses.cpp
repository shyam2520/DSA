class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto& ch:s){
            // if(ch=='(' || ch=='{' || ch=='[') stack.push(ch);
            if(ch==')' && stack.size() && stack.top()=='(') stack.pop();
            else if(ch=='}' && stack.size() && stack.top()=='{') stack.pop();
            else if(ch==']' && stack.size() && stack.top()=='[') stack.pop();
            else stack.push(ch);
            // }
        }
        return stack.size()==0;
    }
};