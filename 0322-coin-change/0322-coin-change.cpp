class Solution {
public:
    int coinCombs(vector<int>& coins,int idx,int amt,vector<vector<int>>& dp){
        if(!amt) return 0;
        if(idx==0){
            if(amt%coins[idx]!=0) return 1e8;
            return amt/coins[idx];
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];

        if(amt>=coins[idx]){
            int take = 1+coinCombs(coins,idx,amt-coins[idx],dp);
            int notake = coinCombs(coins,idx-1,amt,dp);
            return dp[idx][amt]=min(take,notake);
        }
        return dp[idx][amt]=coinCombs(coins,idx-1,amt,dp);
    }

    
    int coinChange(vector<int>& coins, int amount) {
        // take or not take from high - low 
        sort(begin(coins),end(coins));
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=1;i<=amount;i++){
            if(i%coins[0]) dp[0][i]=1e8;
            else dp[0][i]=i/coins[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(j>=coins[i]){
                    int take = 1+dp[i][j-coins[i]];
                    int notake = dp[i-1][j];
                    dp[i][j]=min(take,notake);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        
        int ans =  dp[n-1][amount];
        return ans>=1e8?-1:ans;
    }


};