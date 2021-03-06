[1066.campus-bikes-ii](https://leetcode.com/problems/campus-bikes-ii/)  

On a campus represented as a 2D grid, there are `N` workers and `M` bikes, with `N <= M`. Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker and their assigned bike is minimized.

The Manhattan distance between two points `p1` and `p2` is `Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|`.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/03/06/1261_example_1_v2.png)

  
**Input:** workers = \[\[0,0\],\[2,1\]\], bikes = \[\[1,2\],\[3,3\]\]
  
**Output:** 6
  
**Explanation:** 
  
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/03/06/1261_example_2_v2.png)

  
**Input:** workers = \[\[0,0\],\[1,1\],\[2,0\]\], bikes = \[\[1,0\],\[2,2\],\[2,1\]\]
  
**Output:** 4
  
**Explanation:** 
  
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.
  

**Note:**

1.  `0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000`
2.  All worker and bike locations are distinct.
3.  `1 <= workers.length <= bikes.length <= 10`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, int> dp;
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        return dfs(workers, bikes, 0, 0);
    }
    int dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes, int mask, int w) {
        if(w >= workers.size()) return 0;
        if(dp.count(mask)) return dp[mask];
        int res = INT_MAX;
        for(int i = 0; i < bikes.size(); ++i) {
            if(mask & (1 << i )) continue;
            int dis = abs(workers[w][0] - bikes[i][0]) + abs(workers[w][1] - bikes[i][1]);
            res = min(res, dfs(workers, bikes, mask  | (1 << i), w + 1  ) + dis);
            
        }
        return dp[mask] = res;
    }
};
```
      