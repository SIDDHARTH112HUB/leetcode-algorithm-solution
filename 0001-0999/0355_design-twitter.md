[355.design-twitter](https://leetcode.com/problems/design-twitter/)  

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

1.  **postTweet(userId, tweetId)**: Compose a new tweet.
2.  **getNewsFeed(userId)**: Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
3.  **follow(followerId, followeeId)**: Follower follows a followee.
4.  **unfollow(followerId, followeeId)**: Follower unfollows a followee.

**Example:**

  
Twitter twitter = new Twitter();
  

  
// User 1 posts a new tweet (id = 5).
  
twitter.postTweet(1, 5);
  

  
// User 1's news feed should return a list with 1 tweet id -> \[5\].
  
twitter.getNewsFeed(1);
  

  
// User 1 follows user 2.
  
twitter.follow(1, 2);
  

  
// User 2 posts a new tweet (id = 6).
  
twitter.postTweet(2, 6);
  

  
// User 1's news feed should return a list with 2 tweet ids -> \[6, 5\].
  
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
  
twitter.getNewsFeed(1);
  

  
// User 1 unfollows user 2.
  
twitter.unfollow(1, 2);
  

  
// User 1's news feed should return a list with 1 tweet id -> \[5\],
  
// since user 1 is no longer following user 2.
  
twitter.getNewsFeed(1);  



**Solution:**  

```cpp
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    int t = 0;
    unordered_map<int, vector<pair<int, int> > > userTweet;
    unordered_map<int, unordered_set<int> > followMapping;
    void postTweet(int userId, int tweetId) {
        userTweet[userId].push_back({tweetId, t++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue< pair<int, int> > pq;
        followMapping[userId].insert(userId);
        for(auto followerId : followMapping[userId]){
            //cout<<followerId<<" ";
            auto &tweets = userTweet[followerId];
            int size = tweets.size();
            for(int i = size - 1; i >= max(size-10, 0); --i) {
                pq.push({tweets[i].second, tweets[i].first});
            }
        }
        vector<int> ans;
        while(pq.size() && ans.size() < 10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followMapping[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followMapping[followerId].erase(followeeId);
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
```
      