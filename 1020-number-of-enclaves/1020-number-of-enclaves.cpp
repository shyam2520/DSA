class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // traverse the boundaries  & mark them
        // everything connected to boundary are safe 
        // top & bottom boundary 
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                dfs(grid,visited,0,j);
            }
            if(grid[m-1][j]==1){
                dfs(grid,visited,m-1,j);
            }
        }
        // left & right boundary
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(grid,visited,i,0);
            }
            if(grid[i][n-1]==1){
                dfs(grid,visited,i,n-1);
            }
        }

        int cnt = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]) cnt++;
            }
        }

        return cnt;
    }

    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || 
          grid[i][j]==0 || visited[i][j]) return; 

        visited[i][j]=true;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);

    }
};