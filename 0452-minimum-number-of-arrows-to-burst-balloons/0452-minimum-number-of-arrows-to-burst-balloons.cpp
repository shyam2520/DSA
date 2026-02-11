class Solution {
public:
    using pi = pair<int,int>;
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort the points 
        // conflict internvals array if class max(start),min(end)
        sort(begin(points),end(points));
        vector<pi> ranges; 
        for(auto& i:points){
            int start = i[0];
            int end = i[1];
            if(!ranges.size()) ranges.push_back({start,end});
            else{
                while(ranges.size() && ranges.back().second>=start){
                    pi top = ranges.back();
                    ranges.pop_back();
                    start = max(top.first,start);
                    end = min(top.second,end);
                }
                ranges.push_back({start,end});
            }
        }
        return ranges.size();
    }
};