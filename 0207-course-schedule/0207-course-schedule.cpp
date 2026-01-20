class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. bfs topo sort & check if its a cycle or not 
        queue<int> q; 
        vector<vector<int>> adjMat(numCourses);
        vector<int> indegree(numCourses); 
        for(auto& courses:prerequisites){
            int c1 = courses[0];
            int c2 = courses[1]; 
            adjMat[c2].push_back(c1);
            indegree[c1]++; 
        }

        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i); 
            } 
        } 
        int cnt =0;
        while(q.size()){
            int top = q.front(); 
            cnt++; 
            q.pop();
            for(auto& child:adjMat[top]){
                indegree[child]--; 
                if(!indegree[child]) q.push(child);
            }
        }

        return cnt == numCourses;

    }
};