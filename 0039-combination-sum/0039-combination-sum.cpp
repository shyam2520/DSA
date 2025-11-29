class Solution {
public:
    vector<vector<int>> res;
    
    void combs(vector<int>& cand,int k,int idx,vector<int> temp){
        if(!k){
            res.push_back(temp);
            return ;
        }
        if(idx==cand.size() || cand[idx]>k) return;
        
        temp.push_back(cand[idx]);
        combs(cand,k-cand[idx],idx,temp);
        temp.pop_back();
        combs(cand,k,idx+1,temp);

    }

    vector<vector<int>> combinationSum(vector<int>& cand, int k) {
        sort(begin(cand),end(cand));
        combs(cand,k,0,{});
        return res;
    }
};