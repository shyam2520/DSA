class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i =0;
        int res=0;
        int curr_pos=startFuel;
        priority_queue<int> q;
        for(;curr_pos<target;res++)
        {
            while(i<stations.size() &&stations[i][0]<=curr_pos)
            {
                q.push(stations[i][1]);
                i++;
            }
            if(q.empty())
                return -1;
            curr_pos+=q.top();
            q.pop();
            // priority_queue<int> val;
            // q=val;

        }
        return res;
    }
};