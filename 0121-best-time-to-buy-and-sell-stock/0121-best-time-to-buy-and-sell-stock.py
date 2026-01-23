class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy=-1 
        res = 0 
        for i in range(len(prices)):
            if buy==-1 or prices[i]<prices[buy]: 
                buy = i 
            else: 
                res=max(res,prices[i]-prices[buy])
        return res