class Solution {
public:

    bool subsetExists(vector<int>& nums,int sum,int total,int idx,
    vector<vector<int>>& dp){
        if(sum==total-sum) return true;
        if(idx==nums.size()) return false; 
        if(dp[idx][sum]!=-1) return dp[idx][sum]?true:false;

        dp[idx][sum] = subsetExists(nums,sum+nums[idx],total,idx+1,dp) ||
        subsetExists(nums,sum,total,idx+1,dp);
        return dp[idx][sum]?true:false;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto& i:nums) total+=i;
        vector<vector<int>> dp(nums.size()+1,vector<int>(total+1,-1));
        return subsetExists(nums,0,total,0,dp);
    }
};