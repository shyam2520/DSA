class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        sort(begin(cand),end(cand));
        combsum(cand,target,0,{});
        return res; 
    }

    void combsum(vector<int>& can,int target, int idx,vector<int> temp){
        if(idx==can.size()) return ; 
        if(target-can[idx]==0){
            temp.push_back(can[idx]);
            res.push_back(temp);
            return;
        }
        if(target-can[idx]<0) return ;
        temp.push_back(can[idx]);
        combsum(can,target-can[idx],idx,temp);
        temp.pop_back();
        combsum(can,target,idx+1,temp);
    }
};