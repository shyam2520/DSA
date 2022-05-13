class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_val=INT_MAX,max_val=INT_MIN;
        for(auto& i:piles) 
        {
            min_val=min(min_val,i);
            max_val=max(max_val,i);
        }
        int mid,l=1,r=max_val;
        while(l<r)
        {
            mid=l+(r-l)/2;
            if(hours(piles,mid)<=h) r=mid;
            else l=mid+1;
        }
        return l;
    }
    
    int hours(vector<int>& piles,int speed)
    {
        int total_hours=0;
        for(auto& i:piles)
        {
            total_hours+=i/speed;
            total_hours+=(i%speed)?1:0;
        }
        return total_hours;
    }
};