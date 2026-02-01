class Solution {
public:
    vector<vector<int>> res; 
    void recursion(vector<int>& cand,int st,int target,vector<int> temp){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(st==cand.size()){
            return ;
        }

        for(int i=st;i<cand.size();i++){
            if(i>st && cand[i]==cand[i-1]) continue; 
            if(cand[i]>target) return;
            temp.push_back(cand[i]); 
            recursion(cand,i+1,target-cand[i],temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // at each start point if i>start skip duplicates 
        sort(begin(candidates),end(candidates)); 
        recursion(candidates,0,target,{});
        return res;
        
    }
};