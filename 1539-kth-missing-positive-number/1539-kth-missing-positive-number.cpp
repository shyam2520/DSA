class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int missing=arr[mid]-(mid+1); 
            if(missing>=k) r=mid-1;
            else l=mid+1;
        }
        // r would be point the index which close to k elements ( opposite polarity)
        return k+r+1;

    }
};