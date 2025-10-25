class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0;
        int extra=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            int a = abs(nums1[i]-nums2[i]);
            int b = abs(nums2.back()-nums1[i])+abs(nums2[i]-nums2.back());
            extra=min(extra,abs(nums2.back()-nums1[i]));
            if(a<b) nums1[i]=nums2[i];
            else nums1[i]=nums2.back();
            res+=min(a,b);
            // cout<<nums[i]<<endl;
            extra=min(extra,abs(nums2.back()-nums1[i]));
        }

        return res+extra+1;
    }
};