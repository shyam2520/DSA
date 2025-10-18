/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=0,n=mountainArr.length(),r=n-1; 
        int peak=-1;
        while(l<=r){
            int mid = l+(r-l)/2; 
            if(mid>0 && mountainArr.get(mid)<mountainArr.get(mid-1)) r=mid-1; 
            else {
                peak=mid;
                l=mid+1;
            }
        }
        if(mountainArr.get(peak)==target) return peak;


        l=0,r=peak;
        while(l<=r){
            int mid = l+(r-l)/2;
            int mid_val = mountainArr.get(mid); 
            if(mid_val==target) return mid; 
            if(mid_val>target) r=mid-1;
            else l=mid+1;
        }
        
        l=peak,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int mid_val = mountainArr.get(mid); 
            if(mid_val==target) return mid;
            if(mid_val>target) l=mid+1;
            else r=mid-1;
        }

        return -1;
    }
};