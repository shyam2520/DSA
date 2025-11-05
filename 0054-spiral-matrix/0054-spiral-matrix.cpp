class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0,r=matrix[0].size()-1,u=0,d=matrix.size()-1;
        vector<int> res;
        while(u<=d && l<=r){
            for(int i=l;i<=r;i++) res.push_back(matrix[u][i]);
            u++;

            if(u>d) break;

            for(int i=u;i<=d;i++) res.push_back(matrix[i][r]);
            r--;
            if(r<l) break;

            for(int i=r;i>=l;i--) res.push_back(matrix[d][i]);
            d--;
            if(d<u) break;

            for(int i=d;i>=u;i--) res.push_back(matrix[i][l]);
            l++;
            if(l>r) break;
        }
        return res;
    }
};