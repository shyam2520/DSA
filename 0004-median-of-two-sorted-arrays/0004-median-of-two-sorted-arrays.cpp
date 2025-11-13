class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)  
    {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
            // we want to do binary search on smaller array more optimal
        } 
        int l=0,r=n1;
        int left_half = (n1+n2+1)/2; // how many elements to be present in each half 
        while(l<=r){
            int mid1 = l+(r-l)/2;// no. of elements to consider for arr1 in left half
            int mid2 = left_half - mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if((mid1-1)>=0) l1=nums1[mid1-1];
            if((mid2-1)>=0) l2=nums2[mid2-1];
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2) return max(l1,l2);
                else return ((double)(max(l1,l2))+(double)(min(r1,r2)))/2.0;
            }
            else if(l1>r2) r=mid1-1;
            else l=mid1+1;
        }

        return 0;


    }
};