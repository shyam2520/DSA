class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjMat(n);
        vector<int> indegree(n);
        for(auto& i:prerequisites){
            int a = i[0];
            int b = i[1];
            adjMat[a].push_back(b);
            indegree[b]++;
        }
        queue<int> q; 
        for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
        while(q.size()){
            int course = q.front();
            q.pop();
            for(auto& neigh:adjMat[course]){
                indegree[neigh]--;
                if(!indegree[neigh]) q.push(neigh);
            }
        }
        for(auto& i:indegree) if(i) return false;
        return true;
    }
};