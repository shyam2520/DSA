class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0 ) return false;
        int ones=0,zeros=0;
        while(n)
        {
            ones+=n&1;
            // cout<<(n&1)<<endl;
            zeros+=((n&1)==0)?1:0;
            n>>=1;
            // cout<<n<<endl;
            // cout<<ones<<" "<<zeros<<endl;
        }
        return ones==1 && !(zeros%2);
    }
};