class Solution:
    def getBoquet(self,bloomDay,days,k): 
        anc,cnt=-1,0 
        i=0
        while i<len(bloomDay): 
            if bloomDay[i]<=days:
                anc=i
                while i<len(bloomDay) and bloomDay[i]<=days: 
                    if i-anc+1==k: 
                        cnt+=1
                        break 
                    i+=1
            i+=1
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
            print(mid)
            if self.getBoquet(bloomDay,mid,k)>=m:
                res=mid
                r=mid-1 
            else: 
                l=mid+1 
        return res 