class DisjointSet {
    vector<int> parent, size;
    public:
    DisjointSet(int n) {
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }
    int getParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = getParent(parent[n]);
    }

    void unionBySize(int u, int v) {
        int ultp_u = getParent(u);
        int ultp_v = getParent(v);
        if (ultp_u == ultp_v) return;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        unordered_map<string,int> mapMail;
        DisjointSet ds(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(!mapMail.count(accounts[i][j])){
                    mapMail[accounts[i][j]]=i;
                }
                else{
                    int node=mapMail[accounts[i][j]];
                    ds.unionBySize(node,i);
                }
            }
        }
        int n = accounts.size();
        vector<vector<string>> mails(n); 
        for(auto& data:mapMail){
            string mail=data.first;
            int node = data.second; 
            int ultp = ds.getParent(node);
            mails[ultp].push_back(mail); 
        }
        vector<vector<string>> res;
        for(int i=0;i<n;i++){
            string name = accounts[i][0];
            if(!mails[i].size()) continue;
            vector<string> temp ={name}; 
            vector<string> m = mails[i];
            sort(begin(m),end(m));
            for(auto& mail:m) temp.push_back(mail);
            res.push_back(temp);
        }   

        return res;

    }
};