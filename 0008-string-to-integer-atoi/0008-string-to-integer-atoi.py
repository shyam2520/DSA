class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.strip() 
        if not(s): 
            return 0
        neg = False 
        if s[0]=='-' or s[0]=='+':
            if s[0]=='-':
                neg=True 
            s=s[1:]

        res = 0 
        for val in s: 
            if val.isdigit(): 
                res= res*10+int(val)
            else: 
                break
        res =-res if neg else res
        if res<-2**31:
            return -2**31
        elif res>2**31-1:
            return 2**31-1 
        return res