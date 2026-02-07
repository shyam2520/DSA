class DisjointSet{
    private: 
    vector<int> size,parent;
    public: 
    DisjointSet(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++) parent.push_back(i);
    }

    int getMaxParent(){ 
        int max_parent=-1;
        for(int i=0;i<parent.size();i++){
            if(max_parent==-1 || size[i]>size[max_parent]){
                max_parent=i;
            }
        }
        return max_parent;

    }
    int findParent(int n){
        if(parent[n]==n) return n;
        // cout<<n<<endl;
        return parent[n]=findParent(parent[n]);
    }

    void unionBySize(int u,int v){
        int ultp_u = findParent(u);
        int ultp_v = findParent(v);
        if(ultp_u==ultp_v) return; 
        int sizeu = size[ultp_u];
        int sizev = size[ultp_v]; 
        if(sizeu<sizev){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=sizeu;
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=sizev;
        }
    }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // find the MST thats the number of connections 
        // based on connection you set union find by size  if not then connect with on components 
        int extras =0,disconnect=0;
        DisjointSet ds = DisjointSet(n);
        for(auto& node:connections){
            int u = node[0], v=node[1]; 
            if(ds.findParent(u)==ds.findParent(v)){
                extras++;
                continue;
            }
            ds.unionBySize(u,v);
        }
        int max_parent=ds.getMaxParent();
        for(int i=0;i<n;i++){
            int parent = ds.findParent(i);
            if(parent==i && parent!=max_parent) disconnect++;
        }
        if(extras>=disconnect) return min(extras,disconnect);
        return -1;
       

    }
};