class Solution {
public:
    using ppi = pair<int,pair<int,int>>; 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // pq - {stops,{node,price}}
        priority_queue<ppi,vector<ppi>,greater<>> pq;
        // int n = flights.size(); 
        vector<vector<pair<int,int>>> adjMat(n);
        for(auto& edge:flights){
            int u = edge[0];
            int v = edge[1];
            int cst = edge[2]; 
            adjMat[u].push_back({v,cst}); // {node,price};
        }

        pq.push({0,{src,0}});
        vector<int> dist(n,1e9);
        while(pq.size()){
            auto front = pq.top();
            pq.pop(); 
            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second; 
            for(auto neigh:adjMat[node]){
                int ncost = neigh.second; 
                int nenode = neigh.first; 
                int stpcnt = stops+1;
                int newcost = ncost+cost;
                if(newcost>dist[nenode] || stpcnt>k+1) continue; 
                dist[nenode]=newcost; 
                pq.push({stpcnt,{nenode,newcost}});
            }
        }
        if(dist[dst]==1e9) return -1; 
        return dist[dst];
    }
};