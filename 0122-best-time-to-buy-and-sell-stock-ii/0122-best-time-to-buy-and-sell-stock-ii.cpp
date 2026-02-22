class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2,0),curr(2,0);
        // return buysell(prices,0,1,dp);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    curr[buy]=max(-prices[i]+next[0],next[1]);
                }
                else{
                    curr[buy]=max(prices[i]+next[1],next[0]);
                }
            }
            next=curr;
        }

        return next[1];
    }
};