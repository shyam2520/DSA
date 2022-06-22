class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<=nums2[j]) res.push_back(nums1[i++]);
            else res.push_back(nums2[j++]);
        }
        while(i<nums1.size()) res.push_back(nums1[i++]);
        while(j<nums2.size()) res.push_back(nums2[j++]);
        
        if(res.size()%2) return (double)res[res.size()/2];
        return (double)(res[res.size()/2]+res[res.size()/2 - 1])/2;
        
    }
};