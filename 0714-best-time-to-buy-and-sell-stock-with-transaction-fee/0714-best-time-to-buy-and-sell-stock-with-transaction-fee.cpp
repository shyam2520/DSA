class Solution {
public:
    int buysell(vector<int>& prices,int idx,int& fee,int buy,vector<vector<int>>& dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy]=max(
                -prices[idx]+buysell(prices,idx+1,fee,0,dp),
                buysell(prices,idx+1,fee,1,dp)
            );
        }
        else{
            return dp[idx][buy]=max(
                prices[idx]-fee+buysell(prices,idx+1,fee,1,dp),
                buysell(prices,idx+1,fee,0,dp)
            );
        }
    }
    int maxProfit(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[idx][buy]=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
                }
                else{
                    dp[idx][buy]=max(prices[idx]-fee+dp[idx+1][1],dp[idx+1][0]);
                }
            }
        }
        return dp[0][1];
        // return buysell(prices,0,fee,1,dp);
    }
};