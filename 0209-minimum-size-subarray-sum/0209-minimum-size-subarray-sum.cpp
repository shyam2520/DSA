class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total=0;
        for(auto& i:nums) total+=i;
        if(total<target) return 0;
        int res=nums.size(),sum=0,l=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(l<nums.size() && sum-nums[l]>=target) sum-=nums[l++];
            // cout<<i<<" "<<l<<endl;
            res=sum>=target?min(res,i-l+1):res;
        }
        return res;
    }
};