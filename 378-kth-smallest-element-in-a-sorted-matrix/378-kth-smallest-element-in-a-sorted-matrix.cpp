class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        for(auto& vec:matrix)  for(auto& i:vec) res.push_back(i);
        sort(begin(res),end(res));
        return res[k-1];
    }
};