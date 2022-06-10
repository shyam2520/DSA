class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> dict;
        int l=0,res=0;
        for(int i=0;i<s.length();i++)
        {
            while(dict[s[i]]==1)
            {
                res=max(res,i-l);
                // dict.clear();
                dict[s[l]]--;
                l++;
            }
            dict[s[i]]++;
        }
        return max(res,(int)(s.length()-l));
    }
};