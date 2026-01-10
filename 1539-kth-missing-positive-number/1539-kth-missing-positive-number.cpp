class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // [2,3,4,7,11] k= 2,
        // [0,1,2,3,4]
        // [1,2,3,6,10]
        // [1,1,1,3,6]  
        
        // [1,2,3,4,5,6,7,8,9,10,11] 
        // TC - O(logn)
        int l = 0, r= arr.size()-1; 
        int res = -1;
        if((arr[l]-1)>=k) return k;
        while(l<=r){
            int mid = l+(r-l)/2; 
            int val = arr[mid]; // 11 
            int missing_elements = (val-1) - mid;// actualidx(val-1) - mid( curr_idx)
            if(missing_elements>=k){
                r=mid-1;
            }
            else{
                res=mid; 
                l=mid+1;
            }
        }
        // cout<<res<<" "<<arr[res]<<endl;
        // int res = r;
        int missing_elements = (arr[res]-1) - res;
        cout<<missing_elements<<endl;
        // if(missing_elements<=k){
        k-=missing_elements;
        cout<<k<<endl;
        return arr[res]+k;
        // } 
        // return arr[res]-k;
        // missing>=k;
    }
};