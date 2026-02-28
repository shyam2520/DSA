class Solution {
public:
    int mod=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int cpy = i;
            while(cpy){
                cpy>>=1;
                ans<<=1;
            }
            // ans%=mod;
            ans|=i;
            // cout<<ans<<endl;
            ans%=mod;
            // cout<<ans<<endl;

        }
        return ans%mod;
    }
};