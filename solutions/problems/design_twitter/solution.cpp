class Twitter {
private:
    int timer;
    // userId -> vector<{timestamp, tweetId}>
    unordered_map<int, vector<pair<int, int>>> tweets;
    // followerId -> set of followeeId
    unordered_map<int, unordered_set<int>> followees;

    struct TweetEntry {
        int time;
        int tweetId;
        int userId;
        int index;

        // overload operator< เพื่อให้ priority_queue เรียงจากมากไปน้อยตาม time
        bool operator<(const TweetEntry& other) const {
            return time < other.time;
        }
    };

public:
    Twitter() : timer(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<TweetEntry> maxHeap;

        // รวบรวม user ทั้งหมด (ตัวเอง + คนที่ follow)
        unordered_set<int> users = followees[userId];   // copy
        users.insert(userId);

        for (int u : users) {
            auto it = tweets.find(u);
            if (it != tweets.end() && !it->second.empty()) {
                int idx = it->second.size() - 1;
                maxHeap.push({it->second[idx].first, it->second[idx].second, u, idx});
            }
        }

        vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            auto [time, tweetId, u, idx] = maxHeap.top();
            maxHeap.pop();
            feed.push_back(tweetId);

            if (idx > 0) {
                int nextIdx = idx - 1;
                maxHeap.push({tweets[u][nextIdx].first, tweets[u][nextIdx].second, u, nextIdx});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
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