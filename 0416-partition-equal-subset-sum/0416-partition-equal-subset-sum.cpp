class Solution {
public:

    bool subsetExists(vector<int>& nums,int idx,vector<vector<int>>& dp,int target){
        if(!target) return true;
        if(idx==nums.size()) return false; 
        if(dp[idx][target]!=-1) return dp[idx][target]?true:false;
        if(nums[idx]<=target){
            dp[idx][target] = subsetExists(nums,idx+1,dp,target-nums[idx]) || subsetExists(nums,idx+1,dp,target);
        }
        else{
            dp[idx][target] = false;
        }
        return dp[idx][target];
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto& i:nums) total+=i;
        if(total%2) return false;
        int target = total/2;
        sort(begin(nums),end(nums));
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return subsetExists(nums,0,dp,target);
    }
};