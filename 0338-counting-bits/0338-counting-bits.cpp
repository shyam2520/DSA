class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int val = i;
            while(val){
                cnt+=val&1;
                val>>=1;
            }
            res.push_back(cnt);
        }
        return res;
    }
};