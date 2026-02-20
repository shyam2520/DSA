class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // do LCS tabular and then get the missing characters from smaller string 
        // and append that 
        if(str1.size()<str2.size()){
            return shortestCommonSupersequence(str2,str1);
        }
        int m = str1.size(),n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(str1[i]==str2[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        string lcs = "";
        int i=0,j=0;
        while(i<m && j<n){
            if(str1[i]==str2[j]){
                lcs.push_back(str1[i]);
                i++;j++;
            }
            else{
                if(dp[i+1][j]>dp[i][j+1]) i++;
                else j++;
            }
        }
        int s1=0,s2=0,l1=0;
        string res = "";
        while(s1<m || s2<n){
            if(str1[s1]==lcs[l1] && str2[s2]==lcs[l1]){
                res.push_back(str1[s1]);
                s1++;s2++;l1++;
            }
            if(s1<m && str1[s1]!=lcs[l1]) res.push_back(str1[s1++]);
            if(s2<n && str2[s2]!=lcs[l1]) res.push_back(str2[s2++]);
        }
        return res;
    }
};