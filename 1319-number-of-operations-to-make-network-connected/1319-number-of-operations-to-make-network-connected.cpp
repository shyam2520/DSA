class DisjointSet{
    private: 
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

    void unionBySize(int u,int v){
        int ultp_u = getParent(u);
        int ultp_v = getParent(v);
        if(ultp_u==ultp_v) return ; 
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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        // check if ultp are same if increment extras cnt 
        // if not unionBySize
        // get componentcnt -> min(extras,cmpcnt)
        if(connections.size()<n-1) return -1;
        
        DisjointSet ds(n);
        int extras =0;

        for(auto& edge:connections)
        {
            int u = edge[0];
            int v = edge[1];
            int ultp_u = ds.getParent(u);
            int ultp_v = ds.getParent(v);
            if(ultp_u==ultp_v){
                extras++;
                continue;
            }
            ds.unionBySize(ultp_u,ultp_v);
        }

        int cmpcnt=0;
        for(int i=0;i<n;i++){
            if(ds.getParent(i)==i) cmpcnt++;
        }

        if(cmpcnt-1>extras) return -1;
        return min(extras,cmpcnt-1);
    }
};