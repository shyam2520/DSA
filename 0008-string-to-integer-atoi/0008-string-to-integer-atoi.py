class Solution:
    def validateRes(self,neg,res): 
        if neg: 
            res = -res 
        if res<-(2**31):
            return -(2**31)
        if res>(2**31)-1:
            return 2**31-1 
        return res
    
    def myAtoi(self, s: str) -> int:
        s=s.strip() 
        neg=False
        if not(s):
            return 0
        # print(s)
        if s[0]=='-': 
            neg=True 
            s=s[1:]
        elif s[0]=='+':
            s=s[1:] 
        res=0
        for i in s: 
            if i.isdigit(): 
                res=res*10+int(i) 
            else:
                return self.validateRes(neg,res); 
        
        return self.validateRes(neg,res)



