class Solution {
public:
    int recursion(vector<int>& nums,int idx,int target,vector<vector<int>>& dp){
        if(idx==nums.size()){
            if(!target) return 1; 
            return 0;
        }
        if(dp[idx][target+2000]!=-1) return dp[idx][target+2000];

        if(nums[idx]<=target){
            return dp[idx][target+2000]=recursion(nums,idx+1,target-nums[idx],dp)
            +recursion(nums,idx+1,target,dp);
        }
        return dp[idx][target+2000]=recursion(nums,idx+1,target,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target){
        int total =0; 
        for(auto& i:nums) total+=i; 
        if((target+total)%2) return 0;
        target = (target+total)/2;
        sort(begin(nums),end(nums));
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1+2000,-1));
        return recursion(nums,0,target,dp);
    }
};