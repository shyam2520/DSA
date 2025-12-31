class Solution {
public:
    // int dp[10001]={-1}
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(10001,-1);
        return canJump(0,nums,dp);
    }

    bool canJump(int idx,vector<int>& nums,vector<int>& dp){
        if(idx==nums.size()-1) return true;
        if(idx>=nums.size() ||nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx]==0?false:true;;

        int max_jump = nums[idx];
        for(int i=1;i<=max_jump;i++){
            if(canJump(idx+i,nums,dp)) {
                dp[idx]=1;
                return true;
            };
        }
        dp[idx]=0;
        return false;
    }
};