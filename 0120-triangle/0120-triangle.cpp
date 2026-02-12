class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int  m=triangle.size();
        // vector<vector<int>> dp(m,vector<int>(m));
        vector<int> curr(m);
        vector<int> next(m);
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==m-1) curr[j]=triangle[i][j];
                else{
                    curr[j]=triangle[i][j]+min(next[j],next[j+1]);
                }
            }
            next=curr;
            curr.resize(i);
        }
        return next[0];
    }
};