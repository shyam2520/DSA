class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        if (dividend > 0 && divisor < 0)
        {    neg = true;}
        if (dividend < 0 && divisor > 0)
        {    neg = true;
        }
        // cout<<neg<<endl;
        // if(divisor>dividend) return 0;

        long div = abs((long)(dividend));
        long d = abs((long)(divisor));

        if (div == d)
        {    return neg ? -1 : 1;}
        long ans = 0;

        while (div >= d) {
            long cnt = 0;
            while (div >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += ((long)1 << cnt);
            div -= (d << (cnt));
        }
        cout<<ans<<endl;
        if (ans >= INT_MAX && neg == false) {
            return INT_MAX;
        }
        if (ans >= INT_MAX && neg == true) {
            return INT_MIN;
        }

        return neg ? -ans : ans;
    }
};