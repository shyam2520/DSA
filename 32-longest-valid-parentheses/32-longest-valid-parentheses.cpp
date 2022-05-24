class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1);
        int res=0;
        for(int i=0;i<s.length() ;i++)
        {
            if(s[i]=='(') stack.push(i);
            else
            {
                if(stack.size() && stack.top()!=-1 && s[stack.top()]=='(')
                {
                    stack.pop();
                    res=max(res,i-stack.top());
                }
                else stack.push(i);
            }
        }
        return res;
    }
};