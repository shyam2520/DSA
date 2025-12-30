class compare{
    public: 
    using Node = std::array<int,4>;
    bool operator()(const Node& a,const Node& b){
        return a[0]<b[0];
    }
};
class Twitter {
public:
    // 1. postTweet - > user <-> tweets : map(key,vector<(int,int)>)
    // 2. follow/unfollow -> user <-> follower : map(key,unordered<int>)
    // 3. user-> followers - O(1)
    // 4.  for follow in followe - O(N)
    // 5.       1
    // 6.  pq= O(N) TC - Nlog(n) {time,tweet,idx,follwer}
    // 7. 
    using Node = std::array<int,4>;
    using pii = pair<int,int>;

    unordered_map<int,vector<pii>> tweets;
    unordered_map<int,unordered_set<int>> followers;
    priority_queue<Node,vector<Node>,compare> pq;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        ++time;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // userId-> follow-> userId;
        followers[userId].insert(userId);
        for(auto& follower:followers[userId]){
            // retrieve the last tweets 
            int n = tweets[follower].size();
            if(n==0) continue;
            pii twt = tweets[follower][n-1];
            pq.push({twt.first,twt.second,n-1,follower});
        }
        vector<int> res;
        int cnt =10;
        while(pq.size() && cnt){
            Node top_val = pq.top();
            pq.pop();
            res.push_back(top_val[1]);
            // pq.push({})
            int follower = top_val[3];
            if(top_val[2]-1>=0)
            {
                pii newtweet = tweets[follower][top_val[2]-1];
                pq.push({newtweet.first,newtweet.second,top_val[2]-1,follower});
            }
            cnt--;
        }

        return res;

    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers[followerId].find(followeeId)==followers[followerId].end()){
            return ;
        }
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