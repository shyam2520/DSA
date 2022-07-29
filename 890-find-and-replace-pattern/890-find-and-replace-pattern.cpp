class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto& w:words) if(normalize(w)==normalize(pattern)) res.push_back(w);
        
        return res;
    }
    
    string  normalize(string s)
    {
        unordered_map<int,int> dict;
        for(auto& i:s) dict[i]=dict.size();
        for(int i=0;i<s.length();i++) s[i]='a'+dict[s[i]];
        return s;
    }
};