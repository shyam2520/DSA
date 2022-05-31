//TC : O(N*(M*LOGN(N))
//SC : O(N)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,string> dict;
        sort(begin(folder),end(folder));
        // for(auto& i: folder) cout<<i<<endl;
        for(auto& name:folder)
        {
            // int r=name.length()-1;
            
            string temp=string(1,name[0]);
            
            for(int i=1;i<name.length();i++)
            {
                
                if(name[i]=='/' && dict.count(temp))
                    dict[name]=dict[temp];
                temp+=name[i];
            }
            if(!dict.count(name))
                dict[name]=name;

        
        }
        unordered_set<string> values;
        for(auto& i:dict) values.insert(i.second);
        
        vector<string> res(begin(values),end(values));
        return res;
    }
};