class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=1000000,ans=-1,mid;
        long long total = 0;
        while(l<r){
            mid = l+(r-l)/2;
            total=0;
            for(auto& i:nums) total+=((i/mid) + (i%mid?1:0));

            if(total>threshold) l=mid+1;
            else {
                // ans=mid;
                r=mid;
            }
        }
        return l;
    }
};