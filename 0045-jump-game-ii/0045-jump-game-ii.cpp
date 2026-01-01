class Solution {
public:
    int dp[10001];
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return combs(0,nums);
    }

    int combs(int idx,vector<int>& nums){
        if(idx>=nums.size()-1){
            return 0;
        }
        if(dp[idx]!=-1) {
            return dp[idx];
        }

        int steps = 1e9;
        for(int i=1;i<=nums[idx];i++){
            steps= min(steps,combs(idx+i,nums));
        }
        dp[idx]=1+steps;
        return dp[idx];
    }
};