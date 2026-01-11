class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        // dfs traversal on each node with its respective edges 
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            // int l = i;
            for(int j=0;j<isConnected[i].size();j++){
                if(i==j || !isConnected[i][j]) continue; 
                adjList[i].push_back(j);
            }
        }
        vector<bool> visited(n,false); 

        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]) continue;
            dfs(adjList,i,visited);
            cnt++;
        }
        return cnt; 
    }

    void dfs(vector<vector<int>>& adjList,int idx,vector<bool>& visited){
        visited[idx]=true;
        // explore unvisited neighbours 
        for(auto& node:adjList[idx]){
            if(visited[node]) continue; 
            dfs(adjList,node,visited);
        }
    }
};