class Solution:

    def knapsack(self,coins,idx,amt,dp):
        if idx<0: 
            return float("inf")
        if amt==0:
            return 0 
        
        if dp[idx][amt] is not None:
            return dp[idx][amt]

        if coins[idx]>amt:
            dp[idx][amt]= self.knapsack(coins,idx-1,amt,dp)
            return dp[idx][amt]

        a=self.knapsack(coins,idx,amt-coins[idx],dp)
        # print(a)
        a = a if a==float("inf") else 1+a
        b = self.knapsack(coins,idx-1,amt,dp) 
        dp[idx][amt] = min(a,b)
        return dp[idx][amt]    

    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort() 
        dp = [ [ None  for _ in range(amount+1)] for _ in range(len(coins))]
        ans =  self.knapsack(coins,len(coins)-1,amount,dp)
        return -1 if ans==float("inf") else ans