class Solution {
public:
    int res=0;
    int st=-1,end=-1;
    void checkPalindrome(string& s,int l,int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        
        if((r-1)-(l+1)+1>res){
            res=(r-1)-(l+1)+1;
            end=r-1;
            st=l+1;
        }
    }

    string longestPalindrome(string s) {
        
        for(int i=0;i<s.length();i++){
            checkPalindrome(s,i,i);
            checkPalindrome(s,i,i+1);
        }

        return s.substr(st,res);
    }
};