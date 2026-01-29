class Solution:
    def maxProduct(self, nums: List[int]) -> int: 
        res = float("-inf")
        prod = 1 
        min_prod = float("-inf") # for negative prod 
        for val in nums: 
            prod*=val
            #>0
            if prod>0: 
                res = max(res,prod) 
            #<0 
            elif prod<0: 
                min_prod = max(min_prod,prod)
                if prod!=min_prod: 
                    rem = prod//min_prod
                    print(rem)
                    res = max(res,rem) 
                res=max(res,prod)
            #=0
            else: 
                prod = 1
                min_prod = float("-inf")
            res=max(res,val)
        return res
