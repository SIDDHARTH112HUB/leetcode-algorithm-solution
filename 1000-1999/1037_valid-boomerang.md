[1037.valid-boomerang](https://leetcode.com/problems/valid-boomerang/)  

A _boomerang_ is a set of 3 points that are all distinct and **not** in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.

**Example 1:**

**Input:** \[\[1,1\],\[2,3\],\[3,2\]\]
**Output:** true

**Example 2:**

**Input:** \[\[1,1\],\[2,2\],\[3,3\]\]
**Output:** false

**Note:**

1.  `points.length == 3`
2.  `points[i].length == 2`
3.  `0 <= points[i][j] <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    bool isSame(vector<int> &v1, vector<int> &v2) {
        return v1[0] == v2[0] && v1[1] == v2[1];
    }
    bool isBoomerang(vector<vector<int>>& points) {
        auto p1 = points[0], p2 = points[1], p0 = points[2];
        if(isSame(p1, p2) || isSame(p0, p2) || isSame(p1, p0)) return  false;
        if(p1[1] == p2[1] || p0[1] == p2[1] || p0[1] == p1[1]) {
            return !(p1[1] == p2[1] && p1[1] == p0[1]);
        }
        double s1 = (p0[0] - p1[0]) * 1.0 / (p0[1] - p1[1]);
        double s2 = (p2[0] - p1[0]) * 1.0 / (p2[1] - p1[1]);
        return !(fabs(s1 - s2) < 0.000001);
    }
};
```
      