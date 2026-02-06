class TimeMap {
public:
    // unordered_map<int,set<pair<int,int>>  umap;
    // key->timestamp->val
    unordered_map<string,vector<pair<int,string>>> umap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp,value});
    }   
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> ans = umap[key]; 
        int l=0,r=ans.size()-1;
        string res="";
        while(l<=r){
            int mid = l+(r-l)/2; 
            auto [time,val]=ans[mid];
            if(time<=timestamp){
                res=val;
                l=mid+1;
            }
            else r=mid-1;
        }
        // if(res=="") return ans[0].second;
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */