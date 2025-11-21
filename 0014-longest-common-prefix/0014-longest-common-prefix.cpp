class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs),end(strs));
        string first = strs.front(),last=strs.back();
        string ans="";
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]) return ans;
            else ans+=first[i];
        }
        return ans;
    }
};