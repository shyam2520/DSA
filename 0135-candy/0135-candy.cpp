class compare{
    public:
    using pii = pair<int,int>;
    bool operator()(const pii& a,const pii& b){
        return a.first<b.first;
    }
};
class Solution {
public:
    using pii = pair<int,int>;
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        vector<pii> cr;
        // {rating,idx}
        for(int i=0;i<n;i++) cr.push_back({ratings[i],i});
        sort(cr.begin(),cr.end(),compare());

        for(int i=0;i<n;i++){
            int idx = cr[i].second;
            int rat = cr[i].first;
            int can = candies[idx];
            if(idx>0 && rat>ratings[idx-1]){
                can = can>candies[idx-1]?can:candies[idx-1]+1;
            }
            if(idx<n-1 && rat>ratings[idx+1]){
                can = can>candies[idx+1]?can:candies[idx+1]+1;
            }
            candies[idx] = can;
        }
        int res = 0;
        for(auto& i:candies) res+=i;
        return res;
    }
};