class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> ans;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) ans.push_back(1);
                else ans.push_back(res[i-1][j]+res[i-1][j-1]);
            }
            res.push_back(ans);
        }
        return res;
    }
};