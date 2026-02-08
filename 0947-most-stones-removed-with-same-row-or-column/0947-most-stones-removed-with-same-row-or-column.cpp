class DisjointSet{
    private: 
    vector<int> parent,size; 
    public: 
    DisjointSet(int n){
        size.resize(n ,1); 
        for(int i=0;i<n;i++) parent.push_back(i);
    }
    
    int getParent(int n){
        if(parent[n]==n) return n; 
        return parent[n]=getParent(parent[n]);
    }

    void unionBySize(int u,int v){
        int ultpu = getParent(u);
        int ultpv = getParent(v); 
        if(ultpu==ultpv) return ; 
        int sizeu = size[ultpu];
        int sizev = size[ultpv]; 
        if(sizeu<sizev){
            parent[ultpu]=ultpv;
            size[ultpv]+=sizeu;
        }
        else{
            parent[ultpv]=ultpu;
            size[ultpu]+=sizev;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // make the row & col two be different nodes 
        int maxrow=0,maxcol=0;
        for(auto& stone:stones){
            int x = stone[0];
            int y = stone[1]; 
            maxrow=max(maxrow,x);
            maxcol=max(maxcol,y);
        }
        DisjointSet ds = DisjointSet(maxrow+1+maxcol+1);
        unordered_map<int,int> unqstones;
        for(auto& stone:stones){
            int x = stone[0];
            int y = stone[1];
            ds.unionBySize(x,maxrow+1+y);
            unqstones[x]++;
            unqstones[maxrow+1+y]++;
        }
        int cnt=0;
        for(auto& i:unqstones){
            if(ds.getParent(i.first)==i.first) cnt++;
        }

        return stones.size()-cnt;


    }
};