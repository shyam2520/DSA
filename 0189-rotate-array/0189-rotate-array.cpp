class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!k||!nums.size()%k) return ; 
        k%=nums.size();
        reverse(begin(nums),end(nums));
        reverse(begin(nums),begin(nums)+k);
        reverse(begin(nums)+k,end(nums));
    }
};