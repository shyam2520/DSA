class Solution {
public:
    int buysell(vector<int>& prices,int idx,int buy,vector<vector<int>>& dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy]=max(
                -prices[idx]+buysell(prices,idx+1,0,dp),
                buysell(prices,idx+1,1,dp)
            );
        }
        else{
            return dp[idx][buy]=max(
                prices[idx]+buysell(prices,idx+1,1,dp),
                buysell(prices,idx+1,0,dp)
            );

        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return buysell(prices,0,1,dp);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};