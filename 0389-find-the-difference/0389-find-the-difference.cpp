class Solution {
public:
    char findTheDifference(string s, string t) {
        // if(s.length()!=t.length()+1)
        vector<int> dict(26,0);
        for(int i=0;i<t.length();i++){
            if(i<s.length()) dict[s[i]-'a']++;
            dict[t[i]-'a']--;
        }
        for(int i=0;i<26;i++) if(dict[i]) return (char)(i+'a');
        return '-';
    }
};