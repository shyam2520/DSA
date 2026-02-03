class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse the direction of nodes in graph for adjMat 
        // calculate in the indegree 
        // khan's algo 
        int n=graph.size();
        vector<vector<int>> adjMat(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            int u = i; // u->v to v->u
            for(auto& v:graph[i]){
                adjMat[v].push_back(u);
                indegree[u]++;
            }
        }
        vector<int> res; 
        queue<int> q; 
        for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
        while(q.size()){
            int front = q.front();
            q.pop();
            res.push_back(front);
            for(auto& neigh:adjMat[front]){
                indegree[neigh]--;
                if(!indegree[neigh]) q.push(neigh);
            }
        }
        sort(begin(res),end(res));
        return res;
    }
};