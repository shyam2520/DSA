class Solution {
public:
    int get_days(vector<int>& weights,int cap){
        int days=0,ship_cap=cap;
        for(auto& i:weights){
            if(ship_cap-i<0){
                days++;
                ship_cap=cap;
            }
            ship_cap-=i;
        }
        if(ship_cap>=0) days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=*max_element(begin(weights),end(weights)),r=n*(*max_element(begin(weights),end(weights))),ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(get_days(weights,mid)<=days){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};