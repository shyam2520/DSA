class Solution {
public:
    int recursion(vector<vector<int>>& grid,int x,int y1,int y2,vector<vector<vector<int>>>& dp)
    {
        if(y1==grid[0].size() || y2==grid[0].size() || y1<0 || y2<0) return -1e8; 
        if(x==grid.size()-1){
            if(y1==y2) return grid[x][y1]; // only 1 robot can take this
            else return grid[x][y1]+grid[x][y2];
        
        } 
        if(dp[x][y1][y2]!=-1) return dp[x][y1][y2];
        // all combs
        int maxi = 0,temp=0; 
        for(int j1=-1;j1<2;j1++){
            for(int j2=-1;j2<2;j2++){
                if(y1==y2){
                    temp=grid[x][y1]+recursion(grid,x+1,y1+j1,y2+j2,dp);
                }
                else{
                    temp=grid[x][y1]+grid[x][y2]+recursion(grid,x+1,y1+j1,y2+j2,dp);
                }
                maxi=max(maxi,temp);    
            }
        }
        return dp[x][y1][y2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // each robot can make 3 position 
        // every postion r1 makes r2 can make 3 different change so -> 3*3 = 9 
        int m = grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return recursion(grid,0,0,grid[0].size()-1,dp);
    }
};