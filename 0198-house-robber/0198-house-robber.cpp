class Solution {
public:
    int houserob(vector<int>& nums,int idx){
        if(idx<0) return 0;
        int a = nums[idx]+houserob(nums,idx-2);
        int b = houserob(nums,idx-1);
        return max(a,b);
    }

    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums.back();
        int n = nums.size();
        vector<int> dp(n,0);
        // dp[0]=nums[0];
        int prev2 = nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int curr=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        // return houserob(nums,n-1);
    }
};