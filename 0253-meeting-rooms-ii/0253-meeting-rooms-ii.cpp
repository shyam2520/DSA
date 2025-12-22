class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // [0,30 ],[3,8],[5,10],[15,20] 
        // [0,30] ,[15,20]
        // nlogn + nlogn
        // O(n)
        sort(begin(intervals),end(intervals), [](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]) {
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = intervals.size() ;
        // insert interval
        // if start >endtime of top pop the stack 
        // keep track max stack size 
        int res =0;
        for(int i=0;i<n;i++){
            while(pq.size() && pq.top()<=intervals[i][0]){
                pq.pop();
            }
            pq.push(intervals[i][1]);
            res=max(res,(int)(pq.size()));
        }

        return res;
    }
};