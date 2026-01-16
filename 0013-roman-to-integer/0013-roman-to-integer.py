class Solution:
    def romanToInt(self, s: str) -> int:
        prev_val=None
        prev_char=None 
        roman_dict ={
            'I':1,'V':5,'X':10,
            'L':50,'C':100,'D':500,'M':1000
        }
        res = 0
        for i in s: 
            curr_val = roman_dict[i] 
            if prev_val and curr_val>prev_val: 
                res-=prev_val 
                res+=curr_val-prev_val
            else: 
                res+=curr_val 
            prev_val=curr_val
        return res
            