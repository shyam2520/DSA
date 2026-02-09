class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++) parent.push_back(i);
    }

    int getParent(int n){
        if(parent[n]==n) return n; 
        return parent[n]=getParent(parent[n]);
    }

    int getSize(int n){ return size[n];}

    void unionBySize(int u,int v){
        int ultp_u = getParent(u);
        int ultp_v = getParent(v);
        int size_u = size[ultp_u];
        int size_v = size[ultp_v];
        if(size_u<size_v){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=size_u;
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size_v;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // try to make every 0 -> 1 & create a new obj everytime     
        int m=grid.size(), n=grid[0].size(); 
        vector<vector<int>> visited(m,vector<int>(n));
        DisjointSet ds(m*n+1);
        int res=1;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int curr = n*i+j; 
                for(auto d:dir){
                    int x = i+d[0];
                    int y = j+d[1];
                    if(x<0 || y<0 || x==m || y==n || grid[x][y]==0) continue;
                    int neigh = n*x+y;
                    int ultpc = ds.getParent(curr);
                    int ultpn = ds.getParent(neigh);
                    if(ultpc!=ultpn){
                        ds.unionBySize(curr,neigh);
                        int size = ds.getSize(ds.getParent(curr));
                        res=max(size,res);
                    }
                }
                visited[i][j]=1;
            }
        }

        // repeat for 0 
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int curr = n*i+j; 
                // DisjointSet cpy = ds;
                int cnt=0;
                unordered_map<int,int> dict;
                for(auto d:dir){
                    int x = i+d[0];
                    int y = j+d[1];
                    if(x<0 || y<0 || x==m || y==n || grid[x][y]==0) continue;
                    int neigh = n*x+y;
                    int ultpn = ds.getParent(neigh);
                    if(!dict.count(ultpn)){
                        cnt+=ds.getSize(ultpn);
                        dict[ultpn]++;
                    }
                }
                res=max(res,cnt+1);
            }
        }

        return res;
    }
};