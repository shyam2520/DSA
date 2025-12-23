class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0,alt=0;
        for(int i=0;i<gain.size();i++){
            alt+=gain[i];
            res=max(res,alt);
        }
        return res;
    }
};