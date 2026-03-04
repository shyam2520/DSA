class Solution {
public:
    pair<int,int> checkPalindrome(string& s,int l,int r){
        int prevl=-1,prevr=-1;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            prevl=l;
            prevr=r;
            l--;r++;
        }
        return {prevl,prevr};
    }
    string longestPalindrome(string s) {
        // aba
        // abba
        int n = s.size(); 
        int res = 0,l=-1,r=-1;
        for(int i=0;i<n;i++)
        {
            auto [l1,r1]=checkPalindrome(s,i,i);
            auto [l2,r2]= checkPalindrome(s,i,i+1);
            int len1 = (r1-l1)+1;
            int len2 = (r2-l2)+1;
            if(len1>res){
                res=len1;
                l=l1;r=r1;
            }
            if(len2>res){
                res=len2;
                l=l2,r=r2;
            }
        } 
        return s.substr(l,res);
    }
};