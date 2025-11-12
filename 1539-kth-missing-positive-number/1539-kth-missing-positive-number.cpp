class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count=0,i;
        for(i=1;i<=1000000;i++){
            auto it = lower_bound(begin(arr),end(arr),i);
            if(it==arr.end() || *it!=i) {
                if(++count==k) return i;
            }
            // if(lower_bound(begin(arr),end(arr),i)!=arr.end()) count++;
        }
        return i;
    }
};