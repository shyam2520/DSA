class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dict(26,0);
        for(auto& i:s) dict[i-'a']++;
        for(auto& i:t) dict[i-'a']--;
        for(int i=0;i<26;i++)  if(dict[i]) return false;
        return true;
    }
};