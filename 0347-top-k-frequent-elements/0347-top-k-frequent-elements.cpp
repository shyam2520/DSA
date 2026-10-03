class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // {1,3},{2,2},{3,1}  //  O(N)
        // [,{3},{2},{1},,,] // O(N)
        // hash map to store the freq of ele
        //  cnt srt to store the values in 2D array 
        unordered_map<int,int> dict;
        for(auto& i:nums) dict[i]++;
        int n=nums.size();
        vector<vector<int>> cntsrt(n+1);
        for(auto& i:dict){
            int key =i.first;
            int cnt = i.second;
            cntsrt[cnt].push_back(key);
        }
        vector<int> res;
        for(int i=n;i>=0 && k;i--){
            if(cntsrt[i].empty()) continue;
            while(cntsrt[i].size()){
                res.push_back(cntsrt[i].back());
                cntsrt[i].pop_back();
                k--;
            }
        }
        return res;
    }
};