class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> next(n,0);
    
        
        for(int i=m-1;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) curr[j]=1;
                else{
                    curr[j]=(i+1<m?next[j]:0)+(j+1<n?curr[j+1]:0);
                }
            }
            next=curr;
        }
        return next[0];

    }
};