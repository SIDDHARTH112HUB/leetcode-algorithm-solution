[1401.circle-and-rectangle-overlapping](https://leetcode.com/problems/circle-and-rectangle-overlapping/)  

Given a circle represented as (`radius`, `x_center`, `y_center`) and an axis-aligned rectangle represented as (`x1`, `y1`, `x2`, `y2`), where (`x1`, `y1`) are the coordinates of the bottom-left corner, and (`x2`, `y2`) are the coordinates of the top-right corner of the rectangle.

Return True if the circle and rectangle are overlapped otherwise return False.

In other words, check if there are **any** point (xi, yi) such that belongs to the circle and the rectangle at the same time.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/02/20/sample_4_1728.png)

  
**Input:** radius = 1, x\_center = 0, y\_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1  
**Output:** true  
**Explanation:** Circle and rectangle share the point (1,0)   

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/02/20/sample_2_1728.png)**

  
**Input:** radius = 1, x\_center = 0, y\_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1  
**Output:** true  

**Example 3:**

**![](https://assets.leetcode.com/uploads/2020/03/03/sample_6_1728.png)**

  
**Input:** radius = 1, x\_center = 1, y\_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3  
**Output:** true  

**Example 4:**

  
**Input:** radius = 1, x\_center = 1, y\_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1  
**Output:** false  

**Constraints:**

*   `1 <= radius <= 2000`
*   `-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4`
*   `x1 < x2`
*   `y1 < y2`  



**Solution:**  

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = x_center - max(x1, min(x_center, x2));
        int dy = y_center - max(y1, min(y_center, y2));
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};
```
      