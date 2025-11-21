class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=201;
        string s = "";
        for(int i=0;i<strs.size();i++){
            if(strs[i].length()<n){
                n=strs[i].length();
                s=strs[i];
            }
        }
        int res=n;
        for(auto& temp:strs){
            int i=0;
            for(;i<n;i++) if(temp[i]!=s[i]) break;
            res=min(res,i);
        }
        return s.substr(0,res);
    }
};