class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0, buy_val=INT_MAX;
        for(int i=0;i<prices.size();i++){
            buy_val=min(buy_val,prices[i]);
            res=max(res,prices[i]-buy_val);
        }
        return res;
    }
};