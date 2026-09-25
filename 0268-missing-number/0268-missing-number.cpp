class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xord=0;
        for(int i=0;i<=n;i++) xord^=i;
        for(auto& i:nums) xord^=i;
        return xord;
    }
};