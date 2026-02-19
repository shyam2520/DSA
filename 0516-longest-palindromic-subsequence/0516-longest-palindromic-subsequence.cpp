class Solution {
public:
    int subsequence(string& s,int st,int end,vector<vector<int>>& dp){
        if(st>end) return 0;
        if(st==end){
            if(s[st]==s[end]) return 1;
            return 0;
        }

        if(dp[st][end]!=-1) return dp[st][end];

        if(s[st]==s[end]) return dp[st][end]=2+subsequence(s,st+1,end-1,dp);
        return dp[st][end]=max(
            subsequence(s,st+1,end,dp),
            subsequence(s,st,end-1,dp)
        );
    }

    int longestPalindromeSubseq(string s) {
        int m = s.length();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return subsequence(s,0,s.length()-1,dp);
    }
};