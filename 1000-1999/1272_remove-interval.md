[1272.remove-interval](https://leetcode.com/problems/remove-interval/)  

Given a **sorted** list of disjoint `intervals`, each interval `intervals[i] = [a, b]` represents the set of real numbers `x` such that `a <= x < b`.

We remove the intersections between any interval in `intervals` and the interval `toBeRemoved`.

Return a **sorted** list of `intervals` after all such removals.

**Example 1:**

**Input:** intervals = \[\[0,2\],\[3,4\],\[5,7\]\], toBeRemoved = \[1,6\]  
**Output:** \[\[0,1\],\[6,7\]\]  

**Example 2:**

**Input:** intervals = \[\[0,5\]\], toBeRemoved = \[2,3\]  
**Output:** \[\[0,2\],\[3,5\]\]  

**Constraints:**

*   `1 <= intervals.length <= 10^4`
*   `-10^9 <= intervals[i][0] < intervals[i][1] <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int c = 10000000;
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        map<int, int> m;
        vector<vector<int> > res;
        m[toBeRemoved[0]] += c;
        m[toBeRemoved[1]] -= c;
        for(auto &inter : intervals) {
            int a = inter[0], b = inter[1];
            ++m[a];
            --m[b];
        }
        int prev = -1;
        int cnt;
        for(auto &it : m) {
            int a = it.first;
            cnt += it.second;
            if(cnt == 1) {
                prev = a;
            }else if(cnt > 1) {
                if(cnt >= c) {
                    if(prev != -1) {
                        res.push_back({prev, a});
                    }
                }
                prev = -1;
            }else{
                if(prev != -1) {
                    res.push_back({prev, a});
                }
                prev = -1;
            }
        }
        return res;
    }
};
```
      