class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> idx;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') idx.push_back(i);
            else if(s[i]==')'){
                if(idx.size() && s[idx.back()]=='(') idx.pop_back();
                else idx.push_back(i);
            }
        }
        string res ="";
        int anc=0;
        for(int i=0;i<n;i++){
            if(anc<idx.size() && i==idx[anc]){
                anc++;
                continue;
            }
            res.push_back(s[i]);
        }

        return res;
    }
};