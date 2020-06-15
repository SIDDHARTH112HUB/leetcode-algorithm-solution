[836.rectangle-overlap](https://leetcode.com/problems/rectangle-overlap/)  

A rectangle is represented as a list `[x1, y1, x2, y2]`, where `(x1, y1)` are the coordinates of its bottom-left corner, and `(x2, y2)` are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

**Example 1:**

**Input:** rec1 = \[0,0,2,2\], rec2 = \[1,1,3,3\]
**Output:** true

**Example 2:**

**Input:** rec1 = \[0,0,1,1\], rec2 = \[1,0,2,1\]
**Output:** false

**Notes:**

1.  Both rectangles `rec1` and `rec2` are lists of 4 integers.
2.  All coordinates in rectangles will be between `-10^9` and `10^9`.  



**Solution:**  

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int blx1 = rec1[0], bly1=rec1[1], trx1=rec1[2], try1=rec1[3];
        int blx2 = rec2[0], bly2=rec2[1], trx2=rec2[2], try2=rec2[3];
        return max(blx1, blx2) < min(trx1, trx2 ) && max(bly1, bly2) < min(try1, try2 );
    }
};
```
      