class Solution {
public: 
    int recursion(int idx,vector<int>& dp){
        if(idx<0) return 0;
        if(idx==0) return 1; 
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=recursion(idx-1,dp)+recursion(idx-2,dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return recursion(n,dp);
    }
};