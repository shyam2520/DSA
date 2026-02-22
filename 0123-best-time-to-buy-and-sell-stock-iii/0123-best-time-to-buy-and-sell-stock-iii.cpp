class Solution {
public:
    int recursion(vector<int>& prices, int idx, int buy, int transactions,
                  vector<vector<vector<int>>>& dp) {
        if (transactions == 4 || idx == prices.size())
            return 0;
        if (dp[idx][buy][transactions] != -1)
            return dp[idx][buy][transactions];
        if (buy) {
            return dp[idx][buy][transactions] =
                       max(-prices[idx] + recursion(prices, idx + 1, 0,
                                                    transactions + 1, dp),
                           recursion(prices, idx + 1, buy, transactions, dp));
        } else {
            return dp[idx][buy][transactions] =
                       max(prices[idx] + recursion(prices, idx + 1, 1,
                                                   transactions + 1, dp),
                           recursion(prices, idx + 1, buy, transactions, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(6, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int transactions = 0; transactions < 4; transactions++) {
                    if (buy) {
                        dp[idx][buy][transactions] =
                            max(-prices[idx] + dp[idx + 1][0][transactions + 1],
                                dp[idx + 1][1][transactions]);
                    } else {
                        dp[idx][buy][transactions] = max(
                            prices[idx] + dp[idx + 1][1][transactions + 1],
                            dp[idx + 1][0][transactions]);
                    }
                }
            }
        }
        return dp[0][1][0];
        // return recursion(prices, 0, 1, 0, dp);
    }
};