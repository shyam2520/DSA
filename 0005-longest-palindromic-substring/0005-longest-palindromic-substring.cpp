class Solution {
public:
   pair<int,int> expandFromMiddle(string& s,int l,int r){
        while(l>=0 && r<s.length() && s[l]==s[r]) {
            l--;
            r++;
        }
        return {l+1,r-1};
    }
    string longestPalindrome(string s) {
        string res = "";
        for(int i=0;i<s.length();i++){
            auto [l1,r1] = expandFromMiddle(s,i,i);
            auto [l2,r2] = expandFromMiddle(s,i,i+1);
            int len1 = r1-l1+1;
            int len2 = r2-l2+1;
            if(len1>res.length()) res=s.substr(l1,len1);
            if(len2>res.length()) res=s.substr(l2,len2);
        }
        return res;
    }
};

