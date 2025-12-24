class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(auto& i:nums) total+=i;
        int find = total-x;
        if(find<0) return -1;
        int sum=0,anc=0,res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(anc<=i && sum>find) {
                sum-=nums[anc++];
            }
            if(sum==find){
                res=max(res,i-anc+1);
            }
        }
        return res==INT_MIN?-1:nums.size()-res;
    }
};