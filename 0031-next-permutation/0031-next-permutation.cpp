class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int max=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>=max) max=nums[i];
            else{
                int rev=nums.size()-1;
                while(rev>i && nums[rev]<=nums[i]) rev--;
                swap(nums[rev],nums[i]);
                sort(nums.begin()+i+1,nums.end());
                return ;
            }
        }
        sort(begin(nums),end(nums));
        return ;
    }
};