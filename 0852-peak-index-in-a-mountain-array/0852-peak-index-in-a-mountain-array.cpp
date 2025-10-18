class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        int peak=-1;
        while(l<=r){
            int mid = l+(r-l)/2; 
            if(mid>0 && arr[mid]<arr[mid-1]) r=mid-1;
            else{
                peak=mid;
                l=mid+1;
            } 
        }
        return peak;
    }
};