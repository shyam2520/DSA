class Solution {
public:
    vector<vector<int>> res;
    void combs(vector<int>& cand,int idx,int t,vector<int> temp){
        if(!t) {
            res.push_back(temp);
            return;
        }
        if(idx==cand.size() || cand[idx]>t){
            return;
        }
        temp.push_back(cand[idx]);
        combs(cand,idx+1,t-cand[idx],temp);
        temp.pop_back();
        while(idx+1<cand.size() && cand[idx]==cand[idx+1]) idx++;
        combs(cand,idx+1,t,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {
        sort(begin(cand),end(cand));
        combs(cand,0,t,{});
        return res;
    }
};