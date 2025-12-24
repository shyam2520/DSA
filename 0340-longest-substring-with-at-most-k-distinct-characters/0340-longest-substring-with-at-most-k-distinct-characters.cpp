class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> dict;
        int anc=0,res=0,n=s.length();
        for(int i=0;i<n;i++){
            dict[s[i]]++;
            while(dict.size()>k && anc<=i){
                dict[s[anc]]--;
                if(!dict[s[anc]]){
                    dict.erase(s[anc]);
                }
                anc++;
            }
            res=max(res,i-anc+1);
        }
        return res;
    }
};