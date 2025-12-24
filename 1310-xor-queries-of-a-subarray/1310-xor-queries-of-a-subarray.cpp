class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int xord=0;
        for(int i=0;i<arr.size();i++){
            xord=xord^arr[i];
            arr[i]=xord;
        }

        vector<int> res;
        int n=queries.size();
        for(int i=0;i<n;i++){
            int r = arr[queries[i][1]];
            int l = queries[i][0]-1>=0?arr[queries[i][0]-1]:0;
            res.push_back(r^l);
        }
        return res;
    
    }
};