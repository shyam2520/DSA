class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        string res="";
        stack<char> temp;
        for(int i=0;i<s.length();i++){
            temp.push(s[i]);
            if(s[i]=='(') open++; 
            else open--;
            if(!open){
                string st ="";
                temp.pop();
                while(temp.size()>1) {
                    st+=temp.top();
                    temp.pop();
                }
                reverse(begin(st),end(st));
                res+=st;
                while(!temp.empty()) temp.pop();
            }
        }
        return res;
    }
};