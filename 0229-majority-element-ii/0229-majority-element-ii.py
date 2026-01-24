class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cnt1,ele1=0,None 
        cnt2,ele2=0,None 
        for val in nums: 
            if ele1 is None and val!=ele2: 
                cnt1,ele1 = 1,val 
            elif ele2 is None and val!=ele1: 
                cnt2,ele2=1,val 
            elif val == ele1: 
                cnt1+=1 
            elif val == ele2: 
                cnt2+=1
            else:
                cnt1-=1
                cnt2-=1 
                ele1 = None if cnt1==0 else ele1 
                ele2 = None if cnt2==0 else ele2 

                # if cnt1<=cnt2:
                #     cnt1-=1 
                # else: 
                #     cnt2-=0 
        res = []
        if nums.count(ele1)>len(nums)//3: 
            res.append(ele1)
        if nums.count(ele2)>len(nums)//3: 
            res.append(ele2) 
        res.sort()
        return res
        