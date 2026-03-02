class Solution {
public:
    int minCost(int n) {
        int cost = 0;
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i=0;i<n;i++) pq.push(1);
        while(pq.size()>1){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            cost+= top1*top2;
            pq.push(top1+top2);
        }
        return cost;
    }
};