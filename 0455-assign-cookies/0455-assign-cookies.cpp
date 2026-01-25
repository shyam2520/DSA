class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int l1=0,l2=0;
        int cnt =0;
        while(l1<g.size() && l2<s.size()){
            while(l1<g.size() && l2<s.size() && g[l1]>s[l2]){
                l2++;
            }
            if(l2!=s.size()){
                cnt++;l1++;l2++;
            }
        }

        return cnt;
    }
};