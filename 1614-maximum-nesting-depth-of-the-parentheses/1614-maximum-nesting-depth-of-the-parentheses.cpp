class Solution {
public:
    int maxDepth(string s) {
        int open=0,res=0;
        for(auto& i:s){
            if(i=='(') open++;
            else if(i==')') open--;
            res=max(res,open);
        }
        return res;
    }
};