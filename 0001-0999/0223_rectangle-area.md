[223.rectangle-area](https://leetcode.com/problems/rectangle-area/)  

Find the total area covered by two **rectilinear** rectangles in a **2D** plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

![Rectangle Area](https://assets.leetcode.com/uploads/2018/10/22/rectangle_area.png)

**Example:**

**Input:** A = \-3, B = 0, C = 3, D = 4, E = 0, F = \-1, G = 9, H = 2
**Output:** 45

**Note:**

Assume that the total area is never beyond the maximum possible value of **int**.  



**Solution:**  

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E);
        int right = max( min(C,G), left);
        int bottom = max(B, F);
        int top = max(min(D, H), bottom);
        return abs((A-C)*(B-D)) - abs((left-right)*(bottom-top)) + abs((E-G)*(F-H));
    }
};
```
      