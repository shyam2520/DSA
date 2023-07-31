class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucketSort(nums.size()+1);
        unordered_map<int,int> dict;
        vector<int> res;
        for(auto& i:nums) dict[i]++;
        for(auto& i:dict){
            int count = i.second;
            bucketSort[count].push_back(i.first);
        }
        for(int i=bucketSort.size()-1;i>=0 && res.size()<k;i--){
            while(bucketSort[i].size() && res.size()<k)
            {
                res.push_back(bucketSort[i].back());
                bucketSort[i].pop_back();
            }
        }
        return res;

    }
};