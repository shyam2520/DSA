class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        curr_ele,cnt=0,0 
        for i in nums: 
            if i==curr_ele: 
                cnt+=1 
            else: 
                cnt-=1
                if cnt<0: 
                    curr_ele=i 
                    cnt=1
        return curr_ele