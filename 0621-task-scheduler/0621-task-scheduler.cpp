class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // count the tasks using hashmap 
        // take most frequent tasks reduce by 1 push to queue with the next possible time
        // repeat this operation till task cnt becomes 0 
        // and the time counter matches the next time in queue push the task
        vector<int> dict(26);
        for(auto& i:tasks) if(i) dict[i-'A']++;
        priority_queue<int> pq;
        for(auto& i:dict) if(i) pq.push(i);

        queue<pair<int,int>> q;
        int timer =1;
        while(pq.size() || q.size()){
            while(q.size() && q.front().second<=timer){
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.size()){
                int cnt = pq.top();
                pq.pop();
                if(cnt-1>0) q.push({cnt-1,timer+n+1});
            }
            if(pq.size() || q.size()) timer++;
        }

        return timer;
    }
};