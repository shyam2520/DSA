class Solution {
public:
    using pii = pair<int,int>;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // take every 0 and explore further to the closest 1 
        // in dfs approach there is possibliity that you could have missed out on an opportunity  1,0 -> 2,0->3,0. at return time you 1,0 would be having the lowest value but you can say the same for 2 & 3,0 
        // best is do bfs from every 0 
        int m = mat.size(), n = mat[0].size(); 
        vector<vector<int>> dp(m,vector<int>(n,-1)); 
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pii> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    // bfs 
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        bfs(mat,dp,visited,q);
        return dp;
    }

    void bfs(
        vector<vector<int>>& mat,
        vector<vector<int>>& dp,
        vector<vector<bool>>& visited,
        queue<pii>& q)
    {
        int cnt = 0;
        while(q.size()){
            int n = q.size(); 
            for(int i=0;i<n;i++){
                auto [x,y]=q.front();
                dp[x][y]=cnt;
                q.pop();
                for(auto& i:dir){
                    int newx = i[0]+x;
                    int newy = i[1]+y; 
                    if(newx<0 || newy<0 || newx==mat.size()
                    || newy==mat[0].size() || mat[newx][newy]==0 ||
                    visited[newx][newy]) continue;
                    // dp[newx][newy]=cnt;
                    visited[newx][newy]=true;
                    q.push({newx,newy});
                }   
            }
            cnt++;
        }
    }
};