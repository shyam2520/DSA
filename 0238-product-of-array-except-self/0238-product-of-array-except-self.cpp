class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int zero=0;
        // int prod_without_zero=1;
        for(auto& i:nums)
        {
            if(i) prod*=i;
            if(!i) zero++;
        }
        // if(zero==nums.size()) return vector<int>(nums.size(),0);
        for(auto& i:nums){
            if(i) i=zero?0:prod/i;
            else i=zero-1?0:prod;
        }

        return nums;
        
    }
};