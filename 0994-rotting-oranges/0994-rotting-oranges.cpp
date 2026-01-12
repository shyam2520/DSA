class Solution {
public:
    using pii = pair<int,int>; 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pii> q; 
        int m = grid.size(), n = grid[0].size(); 
        // vector<vector<bool>> visited(m,vicited<int>(n,false));


        // 1. put all rotten oranges in a queue 
        // 2. for each rotten orange do dfs in 4 directions
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                } 
            }
        }

        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int cnt = 0;
        while(q.size()){
            int qsize = q.size();
            // rotten+=n;
            for(int i=0;i<qsize;i++){
                pii top = q.front();
                int x = top.first;
                int y = top.second;
                q.pop(); 
                // cout<<"x:"<<x<<"y:"<<y<<endl;
                for(auto& i:dir){
                    int newx = x+i[0];
                    int newy = y+i[1];
                    // cout<<newx<<" "<<newy<<endl;
                    if(newx<0 || newy<0 || newx>=m || newy>=n || 
                    grid[newx][newy]!=1) 
                    {
                        continue;
                    }
                    // cout<<newx<<" "<<newy<<endl;
                    grid[newx][newy]=2; 
                    q.push({newx,newy});
                }
            }
            cnt++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) if(grid[i][j]==1) return -1;
        }
        return cnt-1;
    }
};