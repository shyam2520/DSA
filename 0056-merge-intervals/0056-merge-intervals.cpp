class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        vector<vector<int>> res;
        for(auto& intr:intervals){
            int a = intr[0];
            int b = intr[1];
            if(!res.size()) res.push_back(intr);
            else{
                vector<int> back = res.back();
                if(back[1]>=a){
                    res.pop_back();
                    a=min(a,back[0]);
                    b=max(b,back[1]);
                }
                res.push_back({a,b});
            }
        }
        return res;
    }
};