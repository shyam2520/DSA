class DisjointSet{
    private: 
    unordered_map<string,string> parent;// email->emal 
    unordered_map<string,int> size; 
    public:
    DisjointSet(){}
    string getParent(string n){
        if(!parent.count(n) || parent[n]==n){
            parent[n]=n;
            return n;
        } 
        parent[n]=getParent(parent[n]);
        return parent[n];
    }

    void unionBySize(string u,string v){
        string ultp_u = getParent(u);
        string ultp_v = getParent(v); 
        if(ultp_u==ultp_v) return ;
        int size_u = size.count(ultp_u)?size[ultp_u]:1;
        int size_v = size.count(ultp_v)?size[ultp_v]:1;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds = DisjointSet();
        unordered_map<string,string> email_name;
        for(auto& acc:accounts){
            string name=acc[0];
            string u = acc[1]; 
            email_name[u]=name;
            // in case there is only one email it needs to exists ds so thats why 
            if(acc.size()==2) ds.unionBySize(u,u);
            for(int i=2;i<acc.size();i++){
                ds.unionBySize(u,acc[i]);
                email_name[acc[i]]=name;
            }
        }
        // unordered_map<string,int> parents; 
        // for(auto& acc:account){
        //     for(int i=1;i<acc.size();i++){
        //         if(ds.getParent(acc[i])==acc[i]) parents[acc[i]]++;
        //     }
        // }

        unordered_map<string,vector<string>> pc; 
        for(auto& acc:accounts){
            for(int i=1;i<acc.size();i++){
                string parent = ds.getParent(acc[i]); 
                if(!pc.count(parent)) pc[parent]={};
                if(parent!=acc[i]) pc[parent].push_back(acc[i]);
            }
        }

        vector<vector<string>> res;
        for(auto& i:pc){
            string acc_name = email_name[i.first];
            vector<string> emails = i.second; // apart from parent 
            emails.push_back(i.first);
            sort(begin(emails),end(emails));

            emails.insert(emails.begin(),acc_name);
            res.push_back(emails);
        }


        return res;
    }
};