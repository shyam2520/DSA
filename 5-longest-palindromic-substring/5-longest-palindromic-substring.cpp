class Solution {
public:
    string longestPalindrome(string s) {
        
        int res=1;
        string ans(1,s[0]);
        for(int i=0;i<s.length();i++)
        {
            int l=i-1,r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]) {l--;r++;}
            // res=max(res,r-l-1);
            if(r-l-1>res)
            {
                res=r-l-1;
                ans=s.substr(l+1,r-l-1);
            }
            l=i;r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]) {l--;r++;}
            if(l!=i && r!=i+1 && res<r-l-1) 
            {
                res=r-l-1;
                ans=s.substr(l+1,r-l-1);
            }
        }
        return ans;
    }
};