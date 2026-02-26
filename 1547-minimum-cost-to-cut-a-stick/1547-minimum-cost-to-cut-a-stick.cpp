class Solution {
public:
    int recursion(vector<int>& cuts,int sidx,int eidx,vector<vector<int>>& dp){
        if(sidx>eidx) return 0;
        if(dp[sidx][eidx]!=-1) return dp[sidx][eidx];
        int cost=cuts[eidx+1]-cuts[sidx-1],res=INT_MAX;

        for(int i=sidx;i<=eidx;i++){
            int newcost = recursion(cuts,sidx,i-1,dp) +recursion(cuts,i+1,eidx,dp);
            res=min(newcost,res);
        }
        return dp[sidx][eidx]=res+cost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));
        // loop through all possible cuts -> cost end-start 
        // update the st & end 
        int size=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(size+1,vector<int>(size+1,-1));
        return recursion(cuts,1,size,dp);
    }
};