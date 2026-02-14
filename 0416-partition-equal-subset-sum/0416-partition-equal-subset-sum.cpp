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
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;

        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=target;j++){
                if(nums[i]<=j) {
                    dp[i][j]=dp[i+1][j-nums[i]]||dp[i+1][j];
                }
                else dp[i][j]=false;
            }
        }
        return dp[0][target];
        // return subsetExists(nums,0,dp,target);
    }
};