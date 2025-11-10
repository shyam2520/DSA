class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        priority_queue<int> pq;
        int prod=1,res=nums[0],zc=0;;
        for(auto& i:nums){
            prod*=i;
            if(prod<0){
                int temp = prod;
                if(pq.size()) temp/=pq.top();
                res=max({res,temp,prod});
                pq.push(prod);
            }
            else if(!prod){
                res=max(res,prod);
                prod=1;
                pq=priority_queue<int>();
            }
            else res=max(res,prod);
        }

        return res;

    }
};