class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> dict;
        int n = nums.size();
        vector<int> res;
        for(auto& i:nums) dict[i]++;
        for(auto& i:dict) if(i.second>n/3) res.push_back(i.first);
        return res;
    }
};