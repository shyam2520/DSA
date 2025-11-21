class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.length(),n=t.length();
        if(m!=n) return false;
        vector<int> dict(26);
        for(int i=0;i<m;i++){
            dict[s[i]-'a']++;
            dict[t[i]-'a']--;
        }

        for(auto& i:dict) if(i) return false;
        return true;
    }
};