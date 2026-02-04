class Solution {
public:
    using pii = pair<int,int>;
    using pli = pair<long long,int>;
    int countPaths(int n, vector<vector<int>>& roads) {
        // same as dijikstras 
        // another cnt arr for ways wt to target < target dst -> replace 
        // another cnt arr for ways wt to target == target cnt 
        // another cnt arr for ways wt to target > skip 
        vector<vector<pii>> adjMat(n); 
        int u,v,wt,mod=1e9+7;
        for(auto& road:roads){
            u = road[0];
            v = road[1];
            wt = road[2]; 
            adjMat[u].push_back({v,wt});// {node,wt}
            adjMat[v].push_back({u,wt});
        }
        priority_queue<pli,vector<pli>,greater<>> pq; //{cost,node} 
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0); 
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(pq.size()){
            auto [cost,node]=pq.top();
            pq.pop(); 
            if(node==n-1){
                return ways[n-1];
            }
            if(cost>dist[node]) continue;
            for(auto& neigh:adjMat[node]){
                auto [nnode,ncost]=neigh;
                long long newcost = (long long)cost+(long long)ncost;
                if(newcost>dist[nnode]) continue; 
                if(newcost==dist[nnode]){
                    ways[nnode]=(ways[nnode] + ways[node])%mod;
                    continue;
                }
                ways[nnode]=ways[node];
                dist[nnode]=newcost;
                pq.push({newcost,nnode});
            }
        }
        return -1;
    }
};