[1182.shortest-distance-to-target-color](https://leetcode.com/problems/shortest-distance-to-target-color/)  

You are given an array `colors`, in which there are three colors: `1`, `2` and `3`.

You are also given some queries. Each query consists of two integers `i` and `c`, return the shortest distance between the given index `i` and the target color `c`. If there is no solution return `-1`.

**Example 1:**

**Input:** colors = \[1,1,2,1,3,2,2,3,3\], queries = \[\[1,3\],\[2,2\],\[6,1\]\]
**Output:** \[3,0,3\]
**Explanation:** 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).

**Example 2:**

**Input:** colors = \[1,2\], queries = \[\[0,3\]\]
**Output:** \[-1\]
**Explanation:** There is no 3 in the array.

**Constraints:**

*   `1 <= colors.length <= 5*10^4`
*   `1 <= colors[i] <= 3`
*   `1 <= queries.length <= 5*10^4`
*   `queries[i].length == 2`
*   `0 <= queries[i][0] < colors.length`
*   `1 <= queries[i][1] <= 3`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<set<int>> col(4);
        for(int i = 0; i < colors.size(); ++i) {
            int c = colors[i];
            col[c].insert(i);
        }
        vector<int> ans;
        for(auto &q : queries) {
            int idx = q[0];
            int c = q[1];
            auto it = col[c].lower_bound(idx);
            if(it == col[c].end()) {
                if(it == col[c].begin()) {
                    ans.push_back(-1);
                    continue;
                }
                --it;
            }
            int r = *it;
            int l = - 10000000;
            if(it != col[c].begin()){
                --it;
                l = *it;
            }
            int res = abs(r-idx) > abs(l - idx) ? abs(l - idx) : abs(r-idx);
            ans.push_back(res);
        }
        return ans;
    }
};
```
      