[391.perfect-rectangle](https://leetcode.com/problems/perfect-rectangle/)  

Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as \[1,1,2,2\]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).

![](https://assets.leetcode.com/uploads/2018/10/22/rectangle_perfect.gif)

**Example 1:**

rectangles = \[
  \[1,1,3,3\],
  \[3,1,4,2\],
  \[3,2,4,4\],
  \[1,3,2,4\],
  \[2,3,3,4\]
\]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

![](https://assets.leetcode.com/uploads/2018/10/22/rectangle_separated.gif)

**Example 2:**

rectangles = \[
  \[1,1,2,3\],
  \[1,3,2,4\],
  \[3,1,4,2\],
  \[3,2,4,4\]
\]

Return false. Because there is a gap between the two rectangular regions.

![](https://assets.leetcode.com/uploads/2018/10/22/rectangle_hole.gif)

**Example 3:**

rectangles = \[
  \[1,1,3,3\],
  \[3,1,4,2\],
  \[1,3,2,4\],
  \[3,2,4,4\]
\]

Return false. Because there is a gap in the top center.

![](https://assets.leetcode.com/uploads/2018/10/22/rectangle_intersect.gif)

**Example 4:**

rectangles = \[
  \[1,1,3,3\],
  \[3,1,4,2\],
  \[1,3,2,4\],
  \[2,2,4,4\]
\]

Return false. Because two of the rectangles overlap with each other.  



**Solution:**  

```cpp
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int > > m;
        long long area = 0;
        for(auto &r :rectangles) {
            pair<int, int> p1 = {r[0], r[1]};
            pair<int, int> p2 = {r[0], r[3]};
            pair<int, int> p3 = {r[2], r[1]};
            pair<int, int> p4 = {r[2], r[3]};
            for(auto &p :{p1, p2, p3, p4}) {
                const auto &r = m.insert(p);
                if(!r.second) {
                    m.erase(r.first);
                }
            }
            area += (r[2] - r[0]) * ( r[3] - r[1]);
        }
        if(m.size() != 4) return false;
        int mnx = INT_MAX, mny = INT_MAX, mxx = 0, mxy = 0;
        for(auto p : m) {
            mxx = max(p.first, mxx);
            mnx = min(p.first, mnx);
            mxy = max(p.second, mxy);
            mny = min(p.second, mny);
        }
        return area == (mxx- mnx) * (mxy - mny);
    }
};

```
      