class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char> dicti,dictj;
        for(int i=0;i<s.length();i++){
            if(dicti.count(s[i]) || dictj.count(t[i]))
            {
                if(dicti[s[i]]!=t[i] ||
                  dictj[t[i]]!=s[i]) return false;
            }
            else{
                dicti[s[i]]=t[i];
                dictj[t[i]]=s[i];
            } 
        }
        return true;
    }
};