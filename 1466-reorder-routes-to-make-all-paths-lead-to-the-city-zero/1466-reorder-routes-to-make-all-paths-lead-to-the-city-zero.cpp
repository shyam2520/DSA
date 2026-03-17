class Solution {
public:

    int res=0;

    bool findEdge(int src,int dest,vector<vector<int>>& adjMat)
    {
        for(auto& neigh:adjMat[src]) if(neigh==dest) return true;
        return false;
    }

    void dfs(
        vector<vector<int>>& uadjMat,vector<vector<int>>& adjMat,
        int root,
        unordered_set<int>& visited
        )
    {
        visited.insert(root);
        for(auto& neigh:uadjMat[root]){
            // check if its an forward edge if so in crement 
            if(visited.find(neigh)!=visited.end()) continue;
            if(findEdge(root,neigh,adjMat)) res++;
            dfs(uadjMat,adjMat,neigh,visited);
        }
        visited.erase(root);

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // create adjMat one for undirected graph 
        // create adjMat for director if child are not pointing  to parent then add 1 
        // if not skip 
        vector<vector<int>> uadjMat(n),adjMat(n);
        for(auto& conn:connections){
            int a = conn[0];
            int b = conn[1];
            uadjMat[a].push_back(b);
            uadjMat[b].push_back(a);

            adjMat[a].push_back(b);
        }
        unordered_set<int> visited; 
        visited.insert(0);
        for(auto& neigh:uadjMat[0]){
            // check if its an forward edge if so in crement 
            if(findEdge(0,neigh,adjMat)) res++;
            dfs(uadjMat,adjMat,neigh,visited);
        }
        return res;
    }
};