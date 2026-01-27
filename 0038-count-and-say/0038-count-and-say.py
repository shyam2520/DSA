class Solution:

    def genString(self,rle): 
        # if n==1:
        #     return "1"
        # rle = self.genString(n-1)
        idx,strlen=0,len(rle)
        ans="" 
        while idx<strlen:
            ch,cnt = rle[idx],0 
            while idx<strlen and rle[idx]==ch:
                cnt+=1 
                idx+=1 
            ans+= str(cnt)+ch
        return ans

    def countAndSay(self, n: int) -> str:
        base = "1"
        ans = base
        for i in range(2,n+1):
            ans=self.genString(ans)
        return ans
