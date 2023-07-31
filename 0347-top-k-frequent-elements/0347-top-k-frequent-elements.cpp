class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> dict;
        priority_queue<pair<int,int>> pq;
        for(auto& i:nums) dict[i]++;
        for(auto& i:dict) pq.push({i.second,i.first});
        vector<int> res;
        while(k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;

    }
};