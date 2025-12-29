class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();
        int cnt =0;
        unordered_map<int,int> dict; 
        for(int i=0;i<n;i++) dict[s[i]]++;
        for(int i=0;i<m;i++) {
            if(dict.count(g[i]) && dict[g[i]]){
                dict[g[i]]--;
                cnt++;
            }
        }

        return cnt;
    }
};