class Twitter {
public:
    Twitter() {
        timestamp = 0;
    }

    struct Tweet {
        int tweetId;
        int timestamp;

        Tweet(int tweetId, int timestamp) {
            this->tweetId = tweetId;
            this->timestamp = timestamp;
        }

        bool operator<(const Tweet other) const {
            return timestamp < other.timestamp;
        }

        operator int() const {
            return tweetId;
        }
    };
    
    void postTweet(int userId, int tweetId) {
        auto& tweetIds = user_tweets[userId];
        Tweet tweet(tweetId, timestamp);
        timestamp++;
        tweetIds.push_back(tweet);
        if (tweetIds.size() > 10) {
            tweetIds.erase(tweetIds.begin(), tweetIds.begin() + 1);
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<Tweet> allTweets = user_tweets[userId];

        for (int followed_user: user_followers[userId]) {
            if (followed_user == userId) continue;
            for (auto tweet: user_tweets[followed_user]) {
                allTweets.push_back(tweet);
            }
        }

        priority_queue<Tweet> min_heap(allTweets.begin(), allTweets.end());
        vector<int> res;
        
        for (int i=0; i<10 && !min_heap.empty(); i++) {
            res.push_back(min_heap.top().tweetId);
            min_heap.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        user_followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_followers[followerId].erase(followeeId);
    }

private:
    unordered_map<int, vector<Tweet>> user_tweets;
    unordered_map<int, unordered_set<int>> user_followers;
    int timestamp;
};
