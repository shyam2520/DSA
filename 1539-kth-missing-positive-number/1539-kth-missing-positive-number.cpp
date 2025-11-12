class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0;i<arr.size();i++){
            int missing_no=i==0?arr[i]-1:arr[i]-arr[i-1]-1;
            if(k-missing_no<=0){
                int l=i-1>=0?arr[i-1]+1:1,r=arr[i]-1,ans=-1;
                int orgl=l,orgr=r;

                while(l<=r){
                    int mid=l+(r-l)/2;
                    if((mid-orgl+1)<=k) {
                        ans=mid;
                        l=mid+1;
                    }
                    else r=mid-1;
                }
                return ans;
            }
            else k-=missing_no;
        }
        if(k) return arr.back()+k;
        return -1;
    }
};