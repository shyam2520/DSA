class compare{
    public:
    using td=std::array<int,4>;
    bool operator()(const td& a,const td& b){
        return a[0]<b[0];
    }
};

class Twitter {
public:
    using pii = pair<int,int>;
    using td = std::array<int,4>; //{time,tweet,follower,idx}
    // user->tweets([time,tweet]) 
    // userid-> follwrIds
    unordered_map<int,unordered_set<int>> fllwrs;
    unordered_map<int,vector<pii>> twts;
    int time=0;
    Twitter() {        
    }
    
    void postTweet(int userId, int tweetId) {
        ++time;
        twts[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<td,vector<td>,compare> pq;
        // get the last tweet of each follower & push it to pq
        fllwrs[userId].insert(userId);
        for(auto fl:fllwrs[userId]){
            int n = twts[fl].size();
            if(n) pq.push({twts[fl][n-1].first,twts[fl][n-1].second,fl,n-1});
        }
        int cnt=10;
        while(cnt && pq.size()){
            td latest = pq.top();
            pq.pop();
            res.push_back(latest[1]);
            int follower = latest[2];
            int idx = latest[3];
            if(idx-1>=0)
            {
                pii twt = twts[follower][idx-1];
                pq.push({twt.first,twt.second,follower,idx-1});
            }
            cnt--;
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        fllwrs[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fllwrs[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */