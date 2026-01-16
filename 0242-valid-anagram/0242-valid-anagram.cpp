class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dicts(26);
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            dicts[s[i]-'a']++;
            dicts[t[i]-'a']--;
        }

        for(auto& i:dicts) if(i!=0) return false; 
        return true;
    }
};