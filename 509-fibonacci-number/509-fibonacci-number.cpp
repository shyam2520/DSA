class Solution {
public:
    int fib(int n) {
        vector<int> res(31,-1);
        res[1]=1;
        res[0]=0;
        return fibo(n,res);
    }
    int fibo(int n,vector<int>& res)
    {
        if(res[n]!=-1) return res[n];
        
        return fibo(n-1,res)+fibo(n-2,res);
    }
};