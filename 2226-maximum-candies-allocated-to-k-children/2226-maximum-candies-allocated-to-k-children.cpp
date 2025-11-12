class Solution {
public:
    unsigned long long no_of_piles(vector<int>& candies,int cand_per_pile){
        unsigned long long total=0;
        for(auto& cand:candies){
            total+=cand/cand_per_pile;
        }
        return total;

    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,r=*max_element(begin(candies),end(candies)),ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;// no of candies per to be present in a pile 
            if(no_of_piles(candies,mid)>=k){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans==-1?0:ans;
    }
};