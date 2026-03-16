class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // 3 array 
        // 1 - adjMat dir graph , 2 - indegree for nodes/course , 3 - months for each course 
        // queue<(node,months)> since min at each level the maxmonths to complete would added in the final reuslt 
        vector<vector<int>> adjMat(n);
        vector<int> indegree(n);
        vector<int> finish(n);
        for(auto& rel:relations){
            int a = rel[0]-1;
            int b = rel[1]-1;
            adjMat[a].push_back(b);
            indegree[b]++;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            int duration = time[i];
            if(indegree[i]==0){
                finish[i]=duration;
                q.push({i,duration});
            } 
        }
        int total = 0;
        while(q.size()){
            int qs = q.size();
            int max_time=0;
            for(int i=0;i<qs;i++){
                auto [course,dur]=q.front();
                q.pop();
                // cout<<course<<endl;
                max_time=max(max_time,dur);
                for(auto& neigh:adjMat[course]){
                    indegree[neigh]--;
                    int newdur = dur+time[neigh];
                    finish[neigh]=max(finish[neigh],newdur);
                    if(indegree[neigh]==0){
                        q.push({neigh,finish[neigh]});
                    }
                }
            }
            // total+=max_time;
            // cout<<total<<endl<<endl;
        }
        return *max_element(begin(finish),end(finish));

    }
};