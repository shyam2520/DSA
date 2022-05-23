class Solution {
    int res=0;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ones=0,zeroes=0;
        vector<pair<int,int>> count(strs.size());
          int dp[601][101][101];
        // vector<vector<vector<int>>> dp(601,vector<vector<int>>(101,vector<int>(101,0)));
        int l=strs.size();
        for(int i=0;i<=l;i++)
        {
            vector<int> nums;
            if(i!=0) nums=calculate(strs[i-1]);
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    if(i==0 || (j==0 && k==0)) dp[i][j][k]=0;
                    else if(nums[0]>j || nums[1]>k) dp[i][j][k]=dp[i-1][j][k];
                    else dp[i][j][k] = max(1+dp[i-1][j-nums[0]][k-nums[1]],dp[i-1][j][k]);
                }
            }
        }
        return dp[l][m][n];
     
        // int size=strs.size();
        // // for(auto& i:strs) cout<<i<<endl;
        // return  knapsack(count,m,n,size,dp);

    }
    vector<int> calculate(string val)
    {
        int ones=0,zeroes=0;
      
            for(auto& i:val)
            {
                if(i=='0') zeroes++;
                else ones++;
            }
            // count[i]={ones,zeroes};
        return {zeroes,ones};
    }
//     int knapsack(vector<pair<int,int>>& strs,int m,int n,int s,vector<vector<vector<int>>>& dp)
//     {
//         if(s==0 ||(m==0 && n==0) ) return 0;

//         if(dp[s][m][n]) return dp[s][m][n];
        
//         int o=strs[s-1].first;
//         int z=strs[s-1].second;
//         if(o>n || z>m) dp[s][m][n]= knapsack(strs,m,n,s-1,dp);
//         else dp[s][m][n]=max(1+knapsack(strs,m-z,n-o,s-1,dp),knapsack(strs,m,n,s-1,dp));
//         return dp[s][m][n];
//     }
    
};