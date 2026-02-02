// class compare{
//     bool operator()(const vector<int>& a,const vector<int>& b)const{
//         if
//     }
// }

class Solution {
public:
    int dfs(vector<vector<int>>& heights, int i, int j, int effort,int x,int y,
            vector<vector<bool>>& visited) 
    {
        if (i < 0 || j < 0 || i == heights.size() || j == heights[0].size() ||
            visited[i][j]) {
            return INT_MAX;
        }
        int neweff = max(effort,heights[i][j]-heights[x][y]);
        if (i == heights.size() - 1 && j == heights[0].size() - 1) {
            return neweff;
        }
        visited[i][j] = true;
        int a = dfs(heights,i+1,j,neweff,i,j,visited);
        int b = dfs(heights,i-1,j,neweff,i,j,visited);
        int c = dfs(heights,i,j+1,neweff,i,j,visited);
        int d = dfs(heights,i,j-1,neweff,i,j,visited);
        visited[i][j] = false; 
        return min({a,b,c,d});
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        // dijkstra with bfs but the weight is based on difference in values
        int m = heights.size(), n = heights[0].size();
        // vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(heights, 0, 0, 0 , 0, 0, visited);
    }
};