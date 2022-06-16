class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        return lcs(s,0,s.length()-1,dp);
    }
    int lcs(string& s,int l,int r,vector<vector<int>>& dp)
    {
        if(l==r) return 1;
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]) dp[l][r]= 2+lcs(s,l+1,r-1,dp);
        else dp[l][r]= max(lcs(s,l+1,r,dp),lcs(s,l,r-1,dp));
        return dp[l][r];
    }
};