class Solution {
public:
    using pii=pair<int,int>; 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // normal dijikstra 
        set<pii> set; 
        vector<int> dist(n+1,INT_MAX); 
        vector<vector<pii>> adjMat(n+1);
        for(auto& t:times){
            int u = t[0];
            int v = t[1];
            int wt = t[2]; 
            adjMat[u].push_back({v,wt});// node,cost 
        }
        set.insert({0,k});

        // pq.push({0,k}); // {cost,node}
        dist[k]=0;
        while(set.size()){
            auto it = set.begin();
            // pq.pop();
            int node = (*it).second;
            int cost = (*it).first; 
            set.erase(it); 
            for(auto& neigh:adjMat[node]){
                int newcost = neigh.second+cost;
                int newnode = neigh.first; 
                if(newcost>=dist[newnode]) continue; 
                // pq.push({newcost,newnode});
                if(newcost!=INT_MAX){
                    set.erase({dist[newnode],newnode});
                }   
                set.insert({newcost,newnode});
                dist[newnode]=newcost;
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<n+1;i++){
            ans=max(ans,dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};