class Solution:
    def checkPal(self,s,l,r): 
        while l>=0 and r<len(s) and s[l]==s[r]:
            l-=1 
            r+=1 
        r-=1 
        l+=1 
        return r-l+1,l,r
    def longestPalindrome(self, s: str) -> str:
        n = len(s) 
        res =""
        for i in range(n): 
            # for even i,i+1 
            # for odd i,i
            a,al,ar = self.checkPal(s,i,i) 
            b,bl,br = self.checkPal(s,i,i+1)
            if a>len(res): 
                res = s[al:ar+1]
            if b>len(res): 
                res = s[bl:br+1]
        return res