class Solution {
public:
    // using pii =pair<int,pair<int,int>>;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> cost(m,vector<int>(n,50000));
        cost[0][0]=0;
        queue<vector<int>> q;
        q.push({0,0,grid[0][0]});
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        while(q.size()){
            vector<int> front = q.front();
            q.pop();
            int i=front[0],j=front[1],c=front[2];
            // cout<<i<<" "<<j<<endl;
            for(auto& coords:dir){
                int x = coords[0]+i;
                int y = coords[1]+j;
                if(x<0 || y<0 || x==grid.size() || y==grid[0].size()) continue;
                int newcost = c+grid[x][y];
                if(newcost>=cost[x][y]) continue;
                cost[x][y]=newcost;
                q.push({x,y,newcost});
            }
        }

        return health>cost[m-1][n-1];
        // return true;

    }
};