class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        vector<vector<int>> res;
        for(int i=0;i<intervals.size();i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];
            while(res.size() && res.back()[1]>=st){
                st=min(st,res.back()[0]);
                ed=max(ed,res.back()[1]);
                res.pop_back();              
            }
            res.push_back({st,ed});
        }
        return res;
    }
};