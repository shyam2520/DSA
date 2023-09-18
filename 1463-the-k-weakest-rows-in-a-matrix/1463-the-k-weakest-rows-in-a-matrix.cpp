class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int soldiers_count=0,m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            soldiers_count=0;
            for(int j=0;j<n;j++) if(mat[i][j]) soldiers_count++;
            q.push({soldiers_count,i});
        }
        vector<int> res;
        while(k--){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};