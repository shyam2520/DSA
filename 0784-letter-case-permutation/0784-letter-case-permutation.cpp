class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        permute(s,0);
        return res;
    }
    void permute(string s,int idx){
        if(idx==s.size()){
            res.push_back(s);
            return;
        }

        if(isalpha(s[idx])){
            permute(s,idx+1);
            s[idx]=islower(s[idx])?toupper(s[idx]):tolower(s[idx]);
            permute(s,idx+1);
        }
        else permute(s,idx+1);
    }
};