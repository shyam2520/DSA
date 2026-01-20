class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        queue<int> q; 
        vector<int> indegree(n,0); 
        vector<vector<int>> adjMat(n); 
        for(auto& course:prereq){
            int c1 = course[0]; 
            int c2 = course[1]; 
            adjMat[c2].push_back(c1); 
            indegree[c1]++; 
        }

        for(int i=0;i<n;i++) if(!indegree[i]) q.push(i); 

        vector<int> res; 
        while(q.size()){
            int cfront = q.front(); 
            q.pop();
            res.push_back(cfront); 
            for(auto n:adjMat[cfront]){
                indegree[n]--; 
                if(!indegree[n]) q.push(n); 
            }
        }
        if(res.size()!=n) return {};
        return res;

    }
};