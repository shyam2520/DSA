class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder),end(folder));
        vector<string> res;
        res.push_back(folder[0]);
        for(int i=1;i<folder.size();i++)
        {
            int idx=folder[i].find(res[res.size()-1]+"/");
            if(idx==string::npos || idx!=0) res.push_back(folder[i]);
        }
        return res;
    }
};