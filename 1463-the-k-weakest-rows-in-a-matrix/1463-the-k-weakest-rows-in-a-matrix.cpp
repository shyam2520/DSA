class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<string> dict(n+1);
        int sc;
        for(int i=0;i<m;i++){
            sc=0;
            for(int j=0;j<n;j++) if(mat[i][j]) sc++;
            dict[sc]+=to_string(i)+' ';
            // cout<<dict[sc]<<endl;
        }
        vector<int> res;
        for(int i=0;i<n+1 && k;i++){
            string rows=dict[i];
            stringstream ss(rows);
            string temp;
            while(ss>>temp && k){
                res.push_back(stoi(temp));
                k--;
            }
        }

        return res;
    }
};