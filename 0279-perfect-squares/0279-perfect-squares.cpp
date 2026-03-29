class Solution {
public:
    int getCombs(vector<int>& ps,int idx,int target,vector<vector<int>>& dp){
        if(!target) return 0;
        if(idx==ps.size() || ps[idx]>target) return INT_MAX;
        if(dp[idx][target]!=-1) return dp[idx][target];

        int a = getCombs(ps,idx,target-ps[idx],dp);
        int b = getCombs(ps,idx+1,target,dp);
        a = a==INT_MAX?INT_MAX:1+a;
        // cout<<a<<" "<<b<<endl;
        return dp[idx][target] = min(a,b)==INT_MAX?INT_MAX:min(a,b);
    }
    int numSquares(int n) {
        // ans = {1,4,9} // sqrt(n) 
        // 1. generate the list of perfect sqs < n
        // 2. combination to sum to n 

        vector<int> ps;
        for(int i=1;(i*i)<=n;i++){
            ps.push_back(i*i);
        }

        int pssize= ps.size();
        vector<vector<int>> dp(pssize,vector<int>(n+1,-1));
        return getCombs(ps,0,n,dp);
    }
};