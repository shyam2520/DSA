class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        int i=0,n=num.length();
        for(;i<n;i++)
        {
            while(stack.size() && k && (stack.top()-'0')>(num[i]-'0')){
                stack.pop();
                k--;
            }
            stack.push(num[i]);
        }
        string ans = "";
        while(stack.size()){
            ans.push_back(stack.top());
            stack.pop();
        }

        reverse(begin(ans),end(ans));
        ans= ans+num.substr(i);
        ans=ans.substr(0,ans.size()-k);
        i=0;
        for(;i<n;i++) if(ans[i]!='0') break;
        ans=ans.substr(i);
        return ans.size()?ans:"0";

    }
};