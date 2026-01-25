class Solution {
public:
    vector<vector<int>> res; 
    void generate(vector<int> nums,int idx){
        if(idx==nums.size()){
            res.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            generate(nums,idx+1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums,0);
        return res;
    }
};