class Solution:
    def getBoquet(self,bloomDay,days,k): 
        window,cnt=0,0
        i=0
        for day in bloomDay: 
            if day<=days:
                window+=1 
                if window==k: 
                    cnt+=1
                    window=0 
            else:
                window=0
        return cnt
        

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:

        # 1.  date range - 1 - max_val(bloomDay)
        # 2. for each day you figure out if the the flowers bloomed can form boquet 
        # 3. return the first the day which it blooms 
        l,r=1,max(bloomDay)
        print(r)
        res = -1 
        while l<=r: 
            mid = l+(r-l)//2 
            if self.getBoquet(bloomDay,mid,k)>=m:
                res=mid
                r=mid-1 
            else: 
                l=mid+1 
        return res 