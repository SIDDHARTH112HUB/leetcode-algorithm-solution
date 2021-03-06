[933.number-of-recent-calls](https://leetcode.com/problems/number-of-recent-calls/)  

Write a class `RecentCounter` to count recent requests.

It has only one method: `ping(int t)`, where t represents some time in milliseconds.

Return the number of `ping`s that have been made from 3000 milliseconds ago until now.

Any ping with time in `[t - 3000, t]` will count, including the current ping.

It is guaranteed that every call to `ping` uses a strictly larger value of `t` than before.

**Example 1:**

  
**Input:** inputs = \["RecentCounter","ping","ping","ping","ping"\], inputs = \[\[\],\[1\],\[100\],\[3001\],\[3002\]\]
  
**Output:** \[null,1,2,3,3\]

**Note:**

1.  Each test case will have at most `10000` calls to `ping`.
2.  Each test case will call `ping` with strictly increasing values of `t`.
3.  Each call to ping will have `1 <= t <= 10^9`.  



**Solution:**  

```cpp
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while( t - q.front() > 3000 )q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```
      