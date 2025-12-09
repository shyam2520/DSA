class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dict(n+1,false);
        int cnt=0;
        for(int i=2;i<n;i++){
            if(dict[i]) continue;
            cnt++;
            for(int j=2;i*j<=n;j++) dict[i*j]=true;
        }
        return cnt;
    }
};