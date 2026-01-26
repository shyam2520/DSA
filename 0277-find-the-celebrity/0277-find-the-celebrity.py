# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        top,bottom = 0,n-1 
        while top<bottom:
            if knows(top,bottom): 
                top+=1 # since top know some one it can't be a celebrity
            elif knows(bottom,top):
                bottom-=1 # since bottoms know some one it can't be a celebrity
            else: 
                # if both don'k knwo each that isn't possible 
                # you can't have two celebs we know for sure that they aren't 
                # case 1 the know the actual cel which we skipped 
                # case 2 there is are no celebs at all 
                top+=1
                bottom-=1 
        
        if top>bottom:# no celebs at all 
            return -1 

        # to confirm if top is the celeb check top know no one and everyone know top 
        for i in range(n): 
            if i==top:
                continue 
            if knows(top,i): 
                return -1 
        
        for i in range(n): 
            if i==top: continue 
            if knows(i,top)==False:
                return -1 
        return top 