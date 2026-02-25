class Solution {
public:
    using pi = pair<int,int>;
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
       // 
       // 0->10^3 
       // V+E
       // 1. adjList 
       // 2. cost array for vertice
       // 1. priority queue to keep track of lowest path {cost,node}
       vector<vector<pi>> adjMat(n); // {node,cost}
       vector<int> dist(n,INT_MAX),cnt(n,0);
        for(auto& road:roads){
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adjMat[u].push_back({v,time});
            adjMat[v].push_back({u,time});
        }
        priority_queue<pi,vector<pi>,greater<>> pq;
        pq.push({0,0}); // {cost,node}
        dist[0]=0;
        cnt[0]=1;
        int res = 0;

        while(pq.size()){
            pi top = pq.top();
            pq.pop();
            auto [cost,node]=top;
            if(node==n-1){
                return cnt[n-1]%mod;
            }
            for(auto& i:adjMat[node]){
                // node,cost 
                auto [v,time]=i;
                if(cost+time==dist[v]){
                    cnt[v]=((cnt[v]%mod)+(cnt[node]%mod))%mod;
                    continue;
                }
                if(cost+time<dist[v]){
                    pq.push({cost+time,v});
                    dist[v]=cost+time;
                    cnt[v]=cnt[node]%mod;
                }
            }
        }

        return res;
    }
};