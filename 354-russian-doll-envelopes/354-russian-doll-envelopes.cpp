class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(begin(e),end(e),[](vector<int>& a,vector<int>& b)->bool{
            return a[0]==b[0]?b[1]<a[1]:a[0]<b[0];
        });
        
        // for(auto& i:e) cout<<i[0]<<" "<<i[1]<<endl;
        vector<int> dp;
        for(auto& i:e)
        {
            int h=i[1];
            int left=lower_bound(begin(dp),end(dp),h)-begin(dp);
            // cout<<h<<" "<<left<<endl;
            if(left==dp.size()) dp.push_back(h);
            dp[left]=h;
        }
        return dp.size();
    }
};