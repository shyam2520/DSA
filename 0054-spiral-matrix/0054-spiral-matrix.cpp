class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // move l to r with u as ref  u++ 
        // move u to d with r as ref r--
        // move r to l with d as ref d--;
        // move d to u with l as ref l++;

        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=n-1,u=0,d=m-1;
        vector<int> res;
        while(u<=d && l<=r){
            for(int i=l;i<=r;i++) res.push_back(matrix[u][i]);
            u++;
            // cout<<u<<" "<<d<<" "<<l<<" "<<r<<endl;
            if(u>d) break;
            for(int i=u;i<=d;i++) res.push_back(matrix[i][r]);
            r--;
            if(r<l) break;
            // cout<<u<<" "<<d<<" "<<l<<" "<<r<<endl;
            for(int i=r;i>=l;i--) res.push_back(matrix[d][i]);
            d--;
            // cout<<u<<" "<<d<<" "<<l<<" "<<r<<endl;
            if(d<u) break;
            for(int i=d;i>=u;i--) res.push_back(matrix[i][l]);
            l++;
            // cout<<u<<" "<<d<<" "<<l<<" "<<r<<endl;
            if(l>r) break;
        }

        return res;
    }
};