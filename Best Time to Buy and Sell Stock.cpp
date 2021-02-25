class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0],max_profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                max_profit=max(max_profit,prices[i]-minprice);
            else 
                minprice=min(minprice,prices[i]);
        }
        return max_profit;
    }
};