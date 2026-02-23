class DisjointSet{
    private: 
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        size.resize(n,1);
        for(int i=0;i<n;i++) parent.push_back(i); 
    }
    int getParent(int n ){
        if(parent[n]==n) return n;
        return parent[n]=getParent(parent[n]);
    }

    void unionBySize(int u,int v){
        int ultp_u = getParent(u);
        int ultp_v = getParent(v);
        int sizeu = size[ultp_u];
        int sizev= size[ultp_v];
        if(ultp_u==ultp_v) return;
        if(sizeu>sizev){
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=sizev;
        }
        else{
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=sizeu;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // get the max rows , cols 
        // ds size row+cols+1
        //  unione of cordinat i,(rows+i)
        int max_rows=0,max_cols=0;
        for(auto& i:stones){
            max_rows=max(max_rows,i[0]);
            max_cols=max(max_cols,i[1]);
        }
        DisjointSet ds(max_rows+max_cols+2);
        unordered_map<int,int> dict;
        for(auto& i:stones){
            int x=i[0],y=i[1];
            y = max_rows+y+1;
            dict[x]++;
            dict[y]++;
            int ultp_u = ds.getParent(x);
            int ultp_v = ds.getParent(y);
            if(ultp_u==ultp_v) continue;
            ds.unionBySize(ultp_u,ultp_v);
        }
        int comp =0;
        // 0 1 2 3
        // 0 0 2 0
        for(auto& i:dict){
            if(i.first==ds.getParent(i.first)) comp++;
        }
        return stones.size()-comp;

    }
};