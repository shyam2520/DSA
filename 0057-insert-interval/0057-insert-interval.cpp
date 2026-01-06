class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> res;
        int i=0;
        for(i=0;i<n && intervals[i][1]<newInterval[0];i++){
            res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        for(;i<n;i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];
            while(res.size() && res.back()[1]>=st){
                st=min(res.back()[0],st);
                ed=max(res.back()[1],ed);
                res.pop_back();
            }
            res.push_back({st,ed});
        }

        return res;

    }
};