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
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=0;i<2;i++){
            dp[n-1][i]=max(0,i?-prices[n-1]:prices[n-1]);
        }
        for(int idx=n-2;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[idx][buy]=max(
                    -prices[idx]+ dp[idx+1][0],
                    dp[idx+1][1]);
                }
                else{
                  dp[idx][buy]=max(
                    prices[idx]+dp[idx+2][1],
                    dp[idx+1][0]);  
                }
            }
        }


        return dp[0][1];
    }
};