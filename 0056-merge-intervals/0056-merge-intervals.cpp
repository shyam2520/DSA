class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        vector<vector<int>> res;
        for(auto& intr:intervals){
            if(res.empty()) res.push_back(intr);
            else{
                int low=intr[0];
                int high=intr[1];
                while(res.size() && res.back()[1]>=low){
                    low=min(low,res.back()[0]);
                    high=max(high,res.back()[1]);
                    res.pop_back();
                }
                res.push_back({low,high});
            }
        }
        return res;
    }
};