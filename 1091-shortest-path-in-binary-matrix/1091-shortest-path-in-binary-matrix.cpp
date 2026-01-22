class Solution {
public:
    using pii = pair<int,int>; 
    vector<vector<int>> dir = {
        {-1,0},{1,0},{0,-1},{0,1},
        {1,1},{1,-1},{-1,-1},{-1,1}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // unordered_set<pii> visited; 
        // visited.insert({0,0});
        if(grid[0][0]==1) return -1;
        queue<pii> q;
        q.push({0,0});
        int cnt = 1;
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==0 && m-1==0 && n-1==0) return 1;
        grid[0][0]=1;
        while(q.size()){
            int qs = q.size();
            for(int i=0;i<qs;i++){
                pii front = q.front(); 
                q.pop(); 
                for(auto& d:dir){
                    int x = d[0]+front.first;
                    int y = d[1]+front.second;
                    if(x<0 || x==m || y<0 || y==n || grid[x][y]==1 ) continue;
                    // cout<<x<<" "<<y<<" "<<grid[x][y]<<endl; 
                    if(x==m-1 && y==n-1) return cnt+1;
                    grid[x][y]=1; 
                    q.push({x,y});
                }
            }
            cnt++;
        }
        return -1;
    }
};