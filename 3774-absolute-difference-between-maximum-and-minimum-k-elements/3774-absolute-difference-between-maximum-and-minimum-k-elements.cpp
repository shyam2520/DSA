class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int suma=0,n=nums.size(),sumb=0;
        for(int i=0;i<k;i++){
            suma+=nums[i];
            sumb+=nums[n-i-1];
        }
        return abs(sumb-suma);
    }
};