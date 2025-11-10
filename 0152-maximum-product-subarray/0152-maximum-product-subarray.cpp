class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int largest_neg=INT_MIN;
        int prod=1,res=nums[0],zc=0;;
        for(auto& i:nums){
            prod*=i;
            if(prod<0){
                int temp = prod;
                if(largest_neg) temp/=largest_neg;
                res=max({res,temp,prod});
                // pq.push(prod);
                largest_neg=max(largest_neg,prod);
            }
            else if(!prod){
                res=max(res,prod);
                prod=1;
                largest_neg=INT_MIN;
            }
            else res=max(res,prod);
        }

        return res;

    }
};