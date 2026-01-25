class Solution:
    def checkPalindrome(self,string): 
        l,r=0,len(string)-1 
        while l<r: 
            if string[l]!=string[r]: 
                return False
            l+=1
            r-=1 
        
        return True 
    
    def genString(self, s:str,idx:int,temp:str,res,comb):
        if idx==len(s): 
            if temp=="": 
                res.append(comb)
            return 
        temp+=s[idx]
        isPal = self.checkPalindrome(temp) 
        if isPal: 
            comb.append(temp)
            self.genString(s,idx+1,"",res,comb.copy())
            comb.pop() 
            self.genString(s,idx+1,temp,res,comb.copy())
        else: 
            self.genString(s,idx+1,temp,res,comb.copy())
            



    def partition(self, s: str) -> List[List[str]]:
        # at each idx i append to string 
        # if palindrome then -> 1. i stop over there add to list 
        # 2. I consider and continue 
        # 3. if not palindrome i have add it continue 
        # 4. when I reach end idx if the current string isn't empty then not pal 
        # so don't push the result 
        res = []
        self.genString(s,0,"",res,[])
        return res

