class Solution {
public:
    int recursion(string& s,int l,int r,vector<vector<int>>& dp){
        if(l>r) return 0;
        if(l==r) return 1; 
        if(s[l]==s[r]) return 2+recursion(s,l+1,r-1,dp);
        if(dp[l][r]!=-1) return dp[l][r];
        return dp[l][r]=max(
            recursion(s,l+1,r,dp),
            recursion(s,l,r-1,dp)
        );
    }

    int minInsertions(string s) {
        // find the longest pal subseq
        // n - longpal = remaining are palindrom 
        int l=0,r=s.size();
        vector<vector<int>> dp(r,vector<int>(r,-1));
        int pal =  recursion(s,l,r-1,dp);
        return r-pal;
    }
};