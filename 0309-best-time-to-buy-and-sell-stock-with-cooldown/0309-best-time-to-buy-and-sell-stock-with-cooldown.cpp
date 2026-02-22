class Solution {
public:
    int buysell(vector<int>& prices,int idx,int buy,vector<vector<int>>& dp){
        if(idx>=prices.size()) return 0;
        if(idx==prices.size()-1) return max(0,buy?-prices[idx]:prices[idx]); 
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy]=max(
                -prices[idx]+ buysell(prices,idx+1,0,dp),
                buysell(prices,idx+1,1,dp)
            );
        }
        else {
            return dp[idx][buy]=max(
                prices[idx]+buysell(prices,idx+2,1,dp),
                buysell(prices,idx+1,0,dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return buysell(prices,0,1,dp);
    }
};