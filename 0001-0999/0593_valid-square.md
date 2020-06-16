[593.valid-square](https://leetcode.com/problems/valid-square/)  

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

**Example:**

  
**Input:** p1 = \[0,0\], p2 = \[1,1\], p3 = \[1,0\], p4 = \[0,1\]
  
**Output:** True
  

Note:

1.  All the input integers are in the range \[-10000, 10000\].
2.  A valid square has four equal sides with positive length and four equal angles (90-degree angles).
3.  Input points have no order.  



**Solution:**  

```cpp
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> m;
        vector<vector<int> > ps = {p1, p2, p3, p4};
        for(int i = 0; i < 4; ++i) {
            for(int j = i+1; j < 4; ++j) {
                auto &a = ps[i], &b = ps[j];
                ++m[(a[1] - b[1]) * (a[1] - b[1]) + (a[0] - b[0]) * (a[0] - b[0])];
            }
        }
        return m.size() == 2 && m[0] == 0;
    }
};
```
      