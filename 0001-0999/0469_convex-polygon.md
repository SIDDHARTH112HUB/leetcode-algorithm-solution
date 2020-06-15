[469.convex-polygon](https://leetcode.com/problems/convex-polygon/)  

Given a list of points that form a polygon when joined sequentially, find if this polygon is convex [(Convex polygon definition)](https://en.wikipedia.org/wiki/Convex_polygon).

**Note:**

1.  There are at least 3 and at most 10,000 points.
2.  Coordinates are in the range -10,000 to 10,000.
3.  You may assume the polygon formed by given points is always a simple polygon [(Simple polygon definition)](https://en.wikipedia.org/wiki/Simple_polygon). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise **don't intersect each other**.

**Example 1:**

\[\[0,0\],\[0,1\],\[1,1\],\[1,0\]\]

Answer: True

Explanation:![](https://assets.leetcode.com/uploads/2018/10/13/polygon_convex.png)

**Example 2:**

\[\[0,0\],\[0,10\],\[10,10\],\[10,0\],\[5,5\]\]

Answer: False

Explanation:![](https://assets.leetcode.com/uploads/2018/10/13/polygon_not_convex.png)  



**Solution:**  

```cpp
class Solution {
public:
    // bool isConvex(vector<vector<int>>& points) {
    //     return outerTrees(points).size() == points.size();
    // }
    
    bool isConvex(vector<vector<int>>& points) {
        vector<vector<int> > res;
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for(auto p : points ) {
            while(res.size() >= 2 && orient(res[res.size()-2], res.back(), p) < 0)
                res.pop_back();
            res.push_back(p);
        }
        for(int i = points.size()-2; i >=0; --i) {
            while(res.size() >= 2 && orient(res[res.size()-2], res.back(), points[i]) < 0) {
                res.pop_back();
            }
            res.push_back(points[i]);
        }
        set<vector<int> > s(res.begin(), res.end());
        return s.size() == points.size();
        //return vector<vector<int> > (s.begin(), s.end());
    }
    
    int orient(vector<int> &p, vector<int> &q, vector<int> &r) {
        return (q[1] - p[1]) * (r[0] - p[0]) - (r[1] - p[1]) * (q[0] - p[0]);
    }
};
```
      