class Solution {
public:
    unsigned long long time(vector<int>& piles,int speed){
        unsigned long long total=0;
        for(auto& pile:piles){
            total+=pile/speed;
            total+=pile%speed?1:0;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(begin(piles),end(piles));
        int ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2; 
            if(time(piles,mid)<=h){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};