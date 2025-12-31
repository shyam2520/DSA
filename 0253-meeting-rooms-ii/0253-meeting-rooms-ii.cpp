struct meetings{
    int start;
    int end;
};

class compare{
    public:
    bool operator()(const meetings& a,const meetings& b){
        if(a.start==b.start) return a.end<b.end;
        return a.start<b.start;
    }
};

class Solution {
public:
    using pii = pair<int,int>;
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<meetings> times;
        meetings temp;
        for(auto& i:intervals){
            temp.start = i[0];
            temp.end = i[1];
            times.push_back(temp);
        }
        sort(times.begin(),times.end(),compare());
        priority_queue<int,vector<int>,greater<>> pq;
        int rooms =1;
        for(int i=0;i<n;i++){
            // if(pq.empty()) pq.push()
            while(pq.size() && times[i].start>=pq.top()) pq.pop();
            pq.push({times[i].end});
            rooms = max(rooms,(int)pq.size());
        }

        return rooms;

    }
};