class DisjointSet{
    private:
    vector<int> parent,size;
    int components = 0;
    public:
    DisjointSet(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++) parent.push_back(i);
    }
    int getParent(int n){
        if(parent[n]==n) {
            return parent[n]=n;
        }
        // int prev = parent[n];
        int par = getParent(parent[n]);
        // if(prev==n && par!=n) components--;
        return parent[n]=par;
    }

    // int getComponents(){ return components;}

    void unionBySize(int u,int v){
        int ultp_u = getParent(u);
        int ultp_v = getParent(v); 
        int size_u = size[ultp_u];
        int size_v = size[ultp_v]; 
        if(ultp_u==ultp_v) return ; 
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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        // make coords as keys -> x-y as string and then disjoint set 
        // sum the coords that will give you node for disjoint set 
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        DisjointSet ds(m*n+1);
        vector<int> res(positions.size(),0);
        unordered_map<int,int> dict;
        int cnt=0;
        for(int i=0;i<positions.size();i++){
            int x = positions[i][0];
            int y = positions[i][1];
            int nodeidx = n*x+y;
            dict[nodeidx] = nodeidx;
            cnt++;
            for(auto& d:dirs){
                int newx = x+d[0];
                int newy = y+d[1];
                if(newx<0 || newy<0 || newx==m || newy==n ) continue;
                int newnodeidx = m*newx+newy;
                if(!dict.count(newnodeidx)) continue;
                int a = ds.getParent(newnodeidx);
                int b = ds.getParent(nodeidx); 
                if(a!=b) cnt--;
                ds.unionBySize(newnodeidx,nodeidx);
                // cnt--;
            }
            int getultp=ds.getParent(nodeidx);
            // cout<<ds.getComponents();
            // if(getultp==nodeidx) cnt++;
            dict[nodeidx]=getultp;
            res[i]=cnt;
            // cnt++;
        }
        return res;
    }
};