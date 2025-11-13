class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)   
    { 
        int m=nums1.size(),n=nums2.size();
        int mid=(m+n)/2;
        int k=0,i=0,j=0;
        int prev=-1,curr=-1;
        while(i<m && j<n && k<=(mid)){
            if(nums1[i]<=nums2[j]){
                prev=curr;
                curr=nums1[i++];
            } 
            else {
                prev=curr;
                curr=nums2[j++];
            }
            k++;
        }
        while(i<m && k<=(mid)){
            prev=curr;
            curr=nums1[i++];
            k++;
        } 
        while(j<n && k<=(mid)){
            prev=curr;
            curr=nums2[j++];
            k++;
        } 

    
        if((m+n)%2==0) return ((double)prev+(double)curr)/2.0;
        return curr; 
    }
};