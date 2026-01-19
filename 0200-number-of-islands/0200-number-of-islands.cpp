class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 1. Do DFS search and set all 1s to 0s as we traverse 
        int m = grid.size(), n = grid[0].size(); 
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    res++; 
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]=='0') return; 
        grid[i][j]='0' ;
        dfs(grid,i+1,j); 
        dfs(grid,i-1,j); 
        dfs(grid,i,j+1); 
        dfs(grid,i,j-1);
    }
};