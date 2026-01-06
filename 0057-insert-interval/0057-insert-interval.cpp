class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(begin(intervals),end(intervals));
        int n = intervals.size();
        for(int i=0;i<n;i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];    
            // conflicting intervals 
            while(res.size() && res.back()[1]>=st){
                int ost = res.back()[0];
                int oed = res.back()[1];
                res.pop_back();
                st = min(st,ost);
                ed = max(ed,oed);
            }
            res.push_back({st,ed});
        }

        return res;
    }
};