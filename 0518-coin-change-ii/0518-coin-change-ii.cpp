class Solution {
public:
    int recursion(vector<int>& nums,int idx,int amt,vector<vector<int>>& dp)
    {  
        if(idx==nums.size()){
            if(!amt) return 1; 
            return 0;
        }   

        if(dp[idx][amt]!=-1){
            return dp[idx][amt];
        }

        if(nums[idx]>amt){
            return dp[idx][amt]=recursion(nums,idx+1,amt,dp);
        }  

        return dp[idx][amt]=recursion(nums,idx,amt-nums[idx],dp) + recursion(nums,idx+1,amt,dp);
    }

    int change(int amount, vector<int>& coins){
        sort(begin(coins),end(coins)); 
        int m=coins.size();
        vector<vector<int>> dp(m+1,vector<int>(amount+1,0));
        // return recursion(coins,0,amount,dp);    
        dp[m][0]=1;
        for(int idx=m-1;idx>=0;idx--){
            for(int amt=0;amt<=amount;amt++){
                if(coins[idx]>amt) dp[idx][amt]=dp[idx+1][amt];
                else{
                    dp[idx][amt]=(long)dp[idx][amt-coins[idx]]+(long)dp[idx+1][amt];
                }
            }
        }

        return dp[0][amount];
    }
};