class Solution {
public:
    int maxLIS(vector<int>& nums,int previdx,int curridx,vector<vector<int>>& dp){
        if((curridx-1)==nums.size()) {
            return 0;
        }
        if(dp[previdx][curridx]!=-1) return dp[previdx][curridx];
        // if(previdx!=-1 && dp[previdx]!=-1) return dp[previdx];

        if((previdx-1)==-1 ||  nums[curridx-1]>nums[previdx-1]){
            return dp[previdx][curridx]=max(
                1+maxLIS(nums,curridx,curridx+1,dp),
                maxLIS(nums,previdx,curridx+1,dp)
            );
        } 
        
        return dp[previdx][curridx]=maxLIS(nums,previdx,curridx+1,dp);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return maxLIS(nums,0,1,dp);
    }
};