class Solution {
public:
    vector<vector<int>> res;
    void generate(vector<int>& nums,int idx,vector<int> temp){
        if(idx==nums.size()) {
            res.push_back(temp);
            return ;
        }
        res.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            generate(nums,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        generate(nums,0,{});
        return res;
    }
};