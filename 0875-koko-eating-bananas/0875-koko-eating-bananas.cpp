class Solution {
public:
    int checkSpeed(vector<int>& piles,int speed){
        int total=0;
        for(auto& pile:piles){
            total+=pile/speed;
            total+=pile%speed?1:0;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //k- spped , h=time, sum(piles)=it has to each
        // 1 to max(piles) - M
        // piles = N 
        // m*n -> n*log(m) 
        int max_piles=*max_element(begin(piles),end(piles));
        int l=1,r=max_piles,res=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checkSpeed(piles,mid)<=h){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return res;
    }
};