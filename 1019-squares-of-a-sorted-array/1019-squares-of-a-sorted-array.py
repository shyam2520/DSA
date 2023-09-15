############################################################
# L0977.py
# Author: Jagadeesh Vasudevamurthy
# Copyright: Jagadeesh Vasudevamurthy 2021

###########################################################
############################################################
# All imports
###########################################################
from typing import List
from time import process_time

########################################
#Nothing can be changed in class Solution
########################################
class Solution:
    #YOU CANNOT CHANGE THIS INTERFACE
    def sortedSquares(self, nums: List[int]) -> List[int]:
        ans = []
        work = [0]
        p = L0977(nums,ans,work,False)
        return ans

########################################
#Nothing can be changed in class L0977
########################################
class L0977:
    def __init__(self,a:List[int], ans:List[int], work:'List of size 1', show:'bool'):
        self._a = a ;
        self._ans = ans ;
        self._work = work ;
        self._show = show ;
        algb = AlgL0977(self,ans,show)

    def size(self)->'int':
        return len(self._a)

    def get(self,i:'int'):
        self._work[0] = self._work[0] + 1
        return self._a[i]

########################################
# WRITE CLASS AlgL0977
#YOU CAN HAVE ANY NUMBER OF PRIVATE VARIABLES and FUNCTIONS
########################################
class AlgL0977():
    def __init__(self,h:'L0977', ans:List[int],show:'bool'):
        self._h = h 
        self._ans = ans 
        self._show = show 
        self._alg()

    ########################################
    #   WRITE YOUR CODE BELOW
    #######################################

    ########################################
    # TIME:THETA(N)
    # Space:THETA(N)
    #########################################
    def _alg(self):
        n = self._h.size();
#         for i in range(n):
        l,r=0,n-1
        res=[]
        while(l<=r):
            l_val=self._h.get(l)
            r_val=self._h.get(r)
            if(l_val**2>=r_val**2):
                res.append(l_val**2)
                l+=1
            else:
                res.append(r_val**2)
                r-=1
        res.reverse()
#         print(f'res : {res}')
        self._ans.extend(res)
#         self._ans=res
        
        
#         print("WRITE CODE BELOW") ## Remove it when done