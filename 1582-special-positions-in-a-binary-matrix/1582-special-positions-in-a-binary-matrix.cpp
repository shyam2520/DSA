class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> rows(m),cols(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!mat[i][j]){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    int rowcnt = rows[i];
                    int colcnt= cols[j];
                    // cout<<rowcnt<<" "<<colcnt<<endl;
                    if(rowcnt==n-1 && colcnt==m-1) res++;
                }
            }
        }

        return res;

    }
};