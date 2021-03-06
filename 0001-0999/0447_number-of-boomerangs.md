[447.number-of-boomerangs](https://leetcode.com/problems/number-of-boomerangs/)  

Given _n_ points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points `(i, j, k)` such that the distance between `i` and `j` equals the distance between `i` and `k` (**the order of the tuple matters**).

Find the number of boomerangs. You may assume that _n_ will be at most **500** and coordinates of points are all in the range **\[-10000, 10000\]** (inclusive).

**Example:**

  
**Input:**
  
\[\[0,0\],\[1,0\],\[2,0\]\]
  

  
**Output:**
  
2
  

  
**Explanation:**
  
The two boomerangs are **\[\[1,0\],\[0,0\],\[2,0\]\]** and **\[\[1,0\],\[2,0\],\[0,0\]\]**  



**Solution:**  

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> m;
            for (int j = 0; j < points.size(); ++j) {
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                ++m[a * a + b * b];
            }
            for (auto it = m.begin(); it != m.end(); ++it) {
                res += it->second * (it->second - 1);
            }
        }
        return res;
    }
};
```
      