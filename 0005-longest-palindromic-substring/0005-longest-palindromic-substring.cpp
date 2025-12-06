class Solution {
public:
    int res = 1;
    string ans="";
    string longestPalindrome(string s) {
        this->ans=s.back();
        for(int i=0;i<s.length();i++){
            isPalindrome(s,i,i);
            isPalindrome(s,i,i+1);
        }

        return this->ans;
    }

    void isPalindrome(string& s,int l,int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        if(r-l>res){
            this->ans=s.substr(l+1,r-l-1);
            res=r-l;
        }
        // return ;
    }
};