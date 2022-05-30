class Solution {
public:
    int divide(long int dividend,long  int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        long int dvd=labs(dividend),dvs=labs(divisor);
        bool sign=(dividend<0) ^ (divisor<0)?true:false;
        long int ans=0;
        // cout<<dvd<<" "<<dvs;
        // cout<<sign<<endl;
         if(divisor==1) return sign? -dvd:dvd;
        while(dvd>=dvs)
        {
            long int temp=dvs,m=1;
            while((temp<<1) <=dvd) 
            {
                temp<<=1;
                // cout<<temp<<endl;
                m<<=1;
            }
            dvd-=temp;
            ans+=m;
        }
        return sign ? -ans:ans;
    }
};