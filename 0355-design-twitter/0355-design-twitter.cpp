class Twitter {
public:
    using pii=pair<int,int>;
    unordered_map<int,vector<pii>> usrtwts;
    unordered_map<int,unordered_set<int>> followers;
    int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        ++time;
        usrtwts[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // 1. get all the followees of the userId
        // 2. merge k sorted lists
        // 3. take all the last values of all the followes and push it into a heap 
        // 4. keep adding those values into the heap till res >10 
        // 5. push the next largest value for a given followeeId 
        vector<pii> tweets; 
        priority_queue<vector<int>> pq; 
        followers[userId].insert(userId);

        for(auto& followee:followers[userId]){
            tweets = usrtwts[followee];
            if(!tweets.size()) continue;
            int idx = tweets.size();
            pq.push({tweets[idx-1].first,tweets[idx-1].second,followee,idx-1}); // max heap 
        }

        vector<int> feed;
        vector<int> res;
        while(pq.size() && res.size()<10){
            feed=pq.top();
            pq.pop();
            res.push_back(feed[1]);
            int idx=feed[3],followee=feed[2];
            tweets = usrtwts[followee];
            if((idx-1)>=0)
            {
                pq.push({tweets[idx-1].first,tweets[idx-1].second,followee,idx-1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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