class Solution {
public:
    bool dfs(vector<vector<int>>& adjMat, vector<int>& visited,
             vector<int>& pathvisited, vector<bool>& nodes, int node) {

        visited[node] = 1;
        pathvisited[node] = 1;
        for (auto& neigh : adjMat[node]) {
            if (visited[neigh] != -1) {
                if (pathvisited[neigh] == 1) {
                    nodes[node]=false;
                    return false;
                }
            } else {
                bool ans = dfs(adjMat, visited, pathvisited, nodes, neigh);
                nodes[node]=nodes[node]&ans;
                if (!ans) return false;
            }
        }

        pathvisited[node] = -1;
        nodes[node]=nodes[node]&true;
        return nodes[node];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adjMat) {
        int n = adjMat.size();
        vector<bool> nodes(n, true);
        vector<int> visited(n, -1), pathvisited(n, -1);

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                bool ans = dfs(adjMat, visited, pathvisited, nodes, i);
                nodes[i]= nodes[i]&ans;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) if (nodes[i]) res.push_back(i);
        return res;
    }
};