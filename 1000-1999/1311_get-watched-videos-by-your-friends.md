[1311.get-watched-videos-by-your-friends](https://leetcode.com/problems/get-watched-videos-by-your-friends/)  

There are `n` people, each person has a unique _id_ between `0` and `n-1`. Given the arrays `watchedVideos` and `friends`, where `watchedVideos[i]` and `friends[i]` contain the list of watched videos and the list of friends respectively for the person with `id = i`.

Level **1** of videos are all watched videos by your friends, level **2** of videos are all watched videos by the friends of your friends and so on. In general, the level `k` of videos are all watched videos by people with the shortest path **exactly** equal to `k` with you. Given your `id` and the `level` of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/01/02/leetcode_friends_1.png)**

  
**Input:** watchedVideos = \[\["A","B"\],\["C"\],\["B","C"\],\["D"\]\], friends = \[\[1,2\],\[0,3\],\[0,3\],\[1,2\]\], id = 0, level = 1  
**Output:** \["B","C"\]   
**Explanation:**   
You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):  
Person with id = 1 -> watchedVideos = \["C"\]   
Person with id = 2 -> watchedVideos = \["B","C"\]   
The frequencies of watchedVideos by your friends are:   
B -> 1   
C -> 2  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/01/02/leetcode_friends_2.png)**

  
**Input:** watchedVideos = \[\["A","B"\],\["C"\],\["B","C"\],\["D"\]\], friends = \[\[1,2\],\[0,3\],\[0,3\],\[1,2\]\], id = 0, level = 2  
**Output:** \["D"\]  
**Explanation:**   
You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).  

**Constraints:**

*   `n == watchedVideos.length == friends.length`
*   `2 <= n <= 100`
*   `1 <= watchedVideos[i].length <= 100`
*   `1 <= watchedVideos[i][j].length <= 8`
*   `0 <= friends[i].length < n`
*   `0 <= friends[i][j] < n`
*   `0 <= id < n`
*   `1 <= level < n`
*   if `friends[i]` contains `j`, then `friends[j]` contains `i`  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> f;
        queue<int> q;
        q.push(id);
        set<int> v;
        v.insert(id);
        while(q.size() && level > 0) {
            int size = q.size();
            while(size-- > 0) {
                int curid = q.front(); q.pop();
                for(auto fri : friends[curid]) {
                    if(v.count(fri) == 0) {
                        q.push(fri);
                        if(level == 1)
                            f.push_back(fri);
                    }
                    v.insert(fri);
                }
            }
            --level;
        }
        map<string, int> m;
        vector<pair<int, string> > pm;
        for(auto fri : f) {
            for(auto &vedio : watchedVideos[fri]) {
                ++m[vedio];
            }
        }
        for(auto it : m) {
            pm.push_back({it.second, it.first});
        }
        sort(pm.begin(), pm.end(), [](auto &a, auto &b){
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        vector<string> ans;
        for(auto &p : pm) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
```
      