class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int anc=0;
        int res = INT_MAX,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(anc<=i && sum>=target){
                res=min(res,i-anc+1);
                sum-=nums[anc++];
            }
        }
        return res==INT_MAX?0:res;
    }
};