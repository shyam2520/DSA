class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // bfs -> go to each room get keys add queue 
        queue<int> q;
        int n = rooms.size();
        vector<bool> visited(n,false);
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int no = q.front();
            q.pop();
            for(auto& keys:rooms[no]){
                if(visited[keys]) continue;
                visited[keys]=true; 
                q.push(keys);
            }
        }
        for(auto i:visited) if(!i) return false;
        return true;
    }
};