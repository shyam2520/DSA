class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_dict;
        unordered_map<char,char> t_dict;
        for(int i =0;i<s.length();i++){
        // we are mapping each character of s to t and mapping each character of t to s 
            if(!s_dict.count(s[i]) && !t_dict.count(t[i]))
            {
                s_dict[s[i]]=t[i];
                t_dict[t[i]]=s[i];

            }
            else 
            {
        // we check if the mapped character is same as actual character we mapped previous if not we            //return false
                if(s_dict.count(s[i]) && s_dict[s[i]]!=t[i])
                    return false;
                else if(t_dict.count(t[i]) &&t_dict[t[i]]!=s[i])
                    return false;
            }
        }
        return true;
    }
};