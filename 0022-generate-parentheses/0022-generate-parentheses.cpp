class Solution {
public:
    vector<string> res;
    void generate(string s,int open,int close){
        if(open==0 && close==0) {
            res.push_back(s);
            return ;
        }
        if(open>=close) generate(s+"(",open-1,close);
        else{
            if(open) generate(s+"(",open-1,close);
            if(close) generate(s+")",open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        generate("",n,n);
        return res;
    }
};