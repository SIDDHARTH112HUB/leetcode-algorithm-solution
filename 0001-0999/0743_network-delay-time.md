[743.network-delay-time](https://leetcode.com/problems/network-delay-time/)  

There are `N` network nodes, labelled `1` to `N`.

Given `times`, a list of travel times as **directed** edges `times[i] = (u, v, w)`, where `u` is the source node, `v` is the target node, and `w` is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node `K`. How long will it take for all nodes to receive the signal? If it is impossible, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

  
**Input:** times = \[\[2,1,1\],\[2,3,1\],\[3,4,1\]\], N = 4, K = 2
  
**Output:** 2
  

**Note:**

1.  `N` will be in the range `[1, 100]`.
2.  `K` will be in the range `[1, N]`.
3.  The length of `times` will be in the range `[1, 6000]`.
4.  All edges `times[i] = (u, v, w)` will have `1 <= u, v <= N` and `0 <= w <= 100`.  



**Solution:**  

```cpp
#define pii pair<int, int>
class Solution {
public:
    unordered_map<int, unordered_map<int, int > > g;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        for(auto &t : times) 
            g[t[0]][t[1]] = t[2];
        unordered_set<int> v;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, K});
        int ans = 0;
        while(pq.size()) {
            auto p = pq.top();
            int w = p.first;
            int n = p.second;
            pq.pop();
            if(v.count(n) == 0)
                ans = max(ans, w);
            v.insert(n);
            for(auto &it : g[n]) {
                int next = it.first;
                int w1 = it.second;
                if(v.count(next) == 0) {
                    pq.push({w + w1, next});
                }
            }
        }
        return v.size() == N ? ans : -1;
    }
};
```
      