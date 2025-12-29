class Solution {
public:
    using pii = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> dict;
        for(auto& i:nums) dict[i]++;
        auto cust_comp = [](const pii& a,const pii& b){
            return a.second>b.second;
        };
        priority_queue<pii,vector<pii>,decltype(cust_comp)> pq(cust_comp);
        for(auto& i:dict){
            pq.push({i.first,i.second});
            if(pq.size()>k) pq.pop();
        }
        vector<int> res;
        while(pq.size()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};