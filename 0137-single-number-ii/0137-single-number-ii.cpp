class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> dict; 
        for(auto& i:nums) dict[i]++;
        for(auto& i:dict) if(i.second==1) return i.first;
        return -1;
    }
};