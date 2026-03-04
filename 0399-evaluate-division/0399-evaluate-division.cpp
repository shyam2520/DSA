class Solution {
public:
    using psd = pair<string,double>;
    double bfs(unordered_map<string,vector<psd>>& adjMat,string src,string dest){
        // start node  put in q 
        // explore neight and multiple  with val -> push 
        // the moment neigh = dest return result 
        queue<psd> q; 
        if(adjMat.find(src)==adjMat.end()) return -1;
        if(src==dest) return 1;
        q.push({src,1.0});  // a->b  b,2 
        unordered_map<string,bool> visited;
        visited[src]=true;
        while(q.size()){
            auto [node,val]=q.front();
            q.pop();
            for(int i=0;i<adjMat[node].size();i++){
                auto neigh = adjMat[node][i];
                auto [nei,v] = neigh;
                if(visited[nei]) continue;
                if(nei==dest) return v*val;
                q.push({nei,v*val});
                visited[nei]=true;
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1. adjMat  num->(denom,val)
        // 2. adjMat  denom->(num,1/val)
        // 3. bfs till you  get the denom
        // 4. if denom is not found I should return -1 
        unordered_map<string,vector<psd>> adjMat;
        for(int i=0;i<equations.size();i++){
            string num = equations[i][0];
            string denom = equations[i][1];
            double val = values[i];
            adjMat[num].push_back({denom,val});
            adjMat[denom].push_back({num,(1/val)});
        }

        vector<double> res;
        for(auto& q:queries){
            double ans = bfs(adjMat,q[0],q[1]);
            res.push_back(ans);
        }

        return res;
    }
};