class Solution:
    def calPow(self,val:float,power:int)->float:
        if power==0: 
            return 1 
        if power==1: 
            return val 
        if power%2==0: 
            ans = self.calPow(val,power/2)
            return ans*ans
        return val*self.calPow(val,power-1)
    
    def myPow(self, x: float, n: int) -> float:
        pow_neg,val_neg=False,False  
        if n<0: 
            pow_neg=True 
            n=abs(n)
        if x<0:  
            if n%2: 
                val_neg = True 
            x=abs(x)
        if x!=1:
            res = self.calPow(x,n)
        else: 
            res = 1 
        res =  -res if val_neg else res 
        res =  1/res if pow_neg else res 
        return res


