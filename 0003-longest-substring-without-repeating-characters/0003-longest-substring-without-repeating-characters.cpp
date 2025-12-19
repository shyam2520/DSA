class Solution {
public:
    bool isValid(string& s,int st,int en,unordered_map<char,int>& dict){  
        for(int i=st;i<=en;i++){
            if(dict[s[i]]>1) return false;
        }

        return true;
    }

    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> dict;
        int anc=0,res=0;
        for(int i=0;i<s.length();i++){
            dict[s[i]]++;
            while(!isValid(s,anc,i,dict)){
                dict[s[anc]]--;
                anc++;
            }
            res=max(res,i-anc+1);
        }

        return res;
    }
};