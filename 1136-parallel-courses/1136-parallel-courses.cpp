class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // adjMat 
        // khan algo with topo 
        vector<vector<int>> adjMat(n);
        vector<int> indegree(n);
        for(auto& r:relations){
            int a= r[0];
            int b = r[1];
            adjMat[a-1].push_back(b-1);
            indegree[b-1]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
        if(!q.size()) return -1;
        int sem=1;
        while(q.size()){
            int qs = q.size();
            for(int i=0;i<qs;i++){
                int cr = q.front();
                q.pop();
                for(auto& neigh:adjMat[cr]){
                    indegree[neigh]--;
                    if(!indegree[neigh]){
                        q.push(neigh);
                    } 
                }
            }
            if(q.size()) sem++;
        }
        for(auto& i:indegree) if(i) return -1;
        return sem;
    }
};