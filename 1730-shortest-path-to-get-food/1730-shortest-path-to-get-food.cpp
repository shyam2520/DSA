class Solution {
public:
    using pos = pair<int,int>;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // int sr=-1,sc=-1;
        queue<pos> q; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='*') {
                    q.push({i,j});
                    break;
                }
            }
        }

        vector<vector<bool>> visited(m,vector<bool>(n,false));
    
        return bfs(grid,visited,q);

    }

    int bfs(
        vector<vector<char>>& grid,
        vector<vector<bool>>& visited,
        queue<pos>& q){
            int cnt =1;
            while(q.size()){
                int n = q.size();
                for(int i=0;i<n;i++){
                    auto [x,y]=q.front(); 
                    q.pop();
                    for(auto& i:dir){
                        int newx = x+i[0]; 
                        int newy = y+i[1]; 
                        if(newx<0 || newy<0 || newx==grid.size() || 
                            newy==grid[0].size() ||
                            grid[newx][newy]=='X'||
                            grid[newx][newy]=='*'||
                            visited[newx][newy]) continue; 
                        if(grid[newx][newy]=='#') return cnt; 
                        visited[newx][newy]=true; 
                        q.push({newx,newy});
                    }
                }
                cnt++;
            }

            return -1;
        }
};