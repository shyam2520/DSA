class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();
        int cnt =0;
        map<int,int> dict; 
        for(int i=0;i<n;i++) dict[s[i]]++;
        for(int i=0;i<m;i++) {
            auto it = dict.lower_bound(g[i]);
            if(it==dict.end()) continue;
            dict[it->first]--;
            cnt++;
            if(dict[it->first]<1) dict.erase(it->first);
        }

        return cnt;
    }
};