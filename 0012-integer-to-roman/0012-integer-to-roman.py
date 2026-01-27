class Solution:
    def intToRoman(self, num: int) -> str:
        romans = {1000: "M", 500: "D", 100: "C", 50: "L", 10: "X", 5: "V", 1: "I"}
        ans = ""
        tens:int = 1 
        while num: 
            curr=num%10 
            if curr==4 or curr==9: 
                val = romans[tens]+romans[int((curr+1)*tens)]
            elif curr<=3: 
                val = romans[tens]*curr 
            else: 
                rem = curr%5 
                val = romans[int(5*tens)] + rem*romans[tens]
            tens*=10
            tens=int(tens)
            ans = val+ans
            num=num//10
        return ans
