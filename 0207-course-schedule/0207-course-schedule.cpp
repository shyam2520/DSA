class Solution {
public:
    bool dfs(vector<vector<int>>& adjMat,int course,
            vector<int>& visited,vector<int>& pathvisited)
    {
        visited[course]=1;
        pathvisited[course]=1;
        for(auto& n:adjMat[course]){
            if(visited[n]!=-1){
                if(pathvisited[n]==1) return true;
            }
            else{
                if(dfs(adjMat,n,visited,pathvisited)) return true; 
            }
        }
        pathvisited[course]=-1;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prereq) {
        // 1. Detect loop using DFS 
        // 2. its would be the same thing how we do normal dfs 
        // 3. we have an addition of path visited because to different path can 
        // end up at the same node doesn't need to form a cycle 
        // 4. so Ideally only if an node is visited & path visited then it is valid
        // 5. during back tracking set pathvisited back to 0 or -1 
        vector<int> visited(n,-1),pathvisited(n,-1); 
        vector<vector<int>> adjMat(n); 

        for(auto& course:prereq){
            int c1 = course[0]; 
            int c2 = course[1]; 
            adjMat[c2].push_back(c1);
        }

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                bool res = dfs(adjMat,i,visited,pathvisited); 
                if(res) return false;
            }
        }
        return true; 
    }
};