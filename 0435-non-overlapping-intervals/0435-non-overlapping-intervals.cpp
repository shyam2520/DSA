class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int cnt = 0,n = intervals.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            // if(res.size()) res.push_back(intervals[i]);
            if(res.size() && res.back()[1]>intervals[i][0]){
                cnt++;
            }
            else res.push_back(intervals[i]);
        }
        return cnt;
    }
};