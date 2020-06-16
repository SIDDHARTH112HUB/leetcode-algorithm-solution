[818.race-car](https://leetcode.com/problems/race-car/)  

Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)

Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).

When you get an instruction "A", your car does the following: `position += speed, speed *= 2`.

When you get an instruction "R", your car does the following: if your speed is positive then `speed = -1` , otherwise `speed = 1`.  (Your position stays the same.)

For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.

Now for some target position, say the **length** of the shortest sequence of instructions to get there.

  
**Example 1:**
  
**Input:** 
  
target = 3
  
**Output:** 2
  
**Explanation:** 
  
The shortest instruction sequence is "AA".
  
Your position goes from 0->1->3.
  

  
**Example 2:**
  
**Input:** 
  
target = 6
  
**Output:** 5
  
**Explanation:** 
  
The shortest instruction sequence is "AAARA".
  
Your position goes from 0->1->3->7->7->6.
  

**Note:**

*   `1 <= target <= 10000`.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> dp;
    int racecar(int target) {
        dp = vector<int>(target + 1);
        return dfs(target);
    }
    
    int dfs(int t){
        if(dp[t]) return dp[t];
        int n = ceil(log2(t + 1));
        if((1 << n) == t+1) return dp[t] = n;
        int res = dfs((1<<n) - t - 1 ) + n + 1;
        for(int m = 0; m < n - 1; ++m) {
            int cur = (1 << (n-1)) - (1<<m);
            res = min(res, m + n + 1 + dfs(t - cur));
        }
        dp[t] = res;
        return res;
    }
    
    
    //BFS
    int racecar1(int target) {
        set<pair<int, int> > m;
        queue<pair<int, int> > q;
        m.insert({0, 1});
        m.insert({0, -1});
        q.push({0, 1});
        int ans = 0;
        while(q.size()){
            int size = q.size();
            while(size-- >0) {
                auto t = q.front();
                q.pop();
                int p = t.first;
                int s = t.second;
                if(p == target)
                    return ans;
                int ns = s * 2;
                if(p + s < target * 2 && p + s > -target && m.count({p + s, ns}) == 0){
                    m.insert({ p+s, ns });
                    q.push({p + s, ns});
                }
                pair<int, int> np= {p, s > 0 ? -1 : 1};
                if(m.count(np) == 0){
                    m.insert(np);
                    q.push(np);
                }
            }
            ++ans;
        }
        return ans;
    }
};
```
      