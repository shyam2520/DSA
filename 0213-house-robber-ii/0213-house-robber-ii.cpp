class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums.back();
        vector<int> dp(n,-1);
        int next=0,next2=0;
        int a = houserob(nums,0,n-2,dp);
        // dp=vector<int>(n,-1);
        int b = houserob(nums,1,n-1,dp);
        return max(a,b);
    }

    int houserob(vector<int>& nums,int s,int e,vector<int> dp){
        // if(idx>=e) return 0;
        // if(dp[idx]!=-1) return dp[idx];
        // int a = houserob(nums,idx+1,e,dp);
        // int b = nums[idx]+houserob(nums,idx+2,e,dp);
        // return dp[idx]=max(a,b);
        dp[e]=nums[e];

        for(int i=e-1;i>=s;i--){
            int a = dp[i+1];
            int b= nums[i]+(i+2>e?0:dp[i+2]);
            dp[i]=max(a,b);
        }
        return max(dp[s],dp[e]);
    }
};