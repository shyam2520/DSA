class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dict(n,false);
        int cnt=0;
        for(int i=2;i<n;i++){
            if(dict[i]) continue;
            cnt++;
            for(int j=i;(long)i*(long)j<n;j++) dict[i*j]=true;
        }
        return cnt;
    }
};