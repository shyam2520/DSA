class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(k>num) return -1;
        for(int i=1;i<=10;i++)
        {
            int res=k*i;
            if(res%10==num%10)
            {
                if(res > num) return -1;
                return i;
            }
        }
        return -1;
    }
};