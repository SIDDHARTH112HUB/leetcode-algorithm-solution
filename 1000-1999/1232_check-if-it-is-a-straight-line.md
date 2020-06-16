[1232.check-if-it-is-a-straight-line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)  

You are given an array `coordinates`, `coordinates[i] = [x, y]`, where `[x, y]` represents the coordinate of a point. Check if these points make a straight line in the XY plane.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg)

  
**Input:** coordinates = \[\[1,2\],\[2,3\],\[3,4\],\[4,5\],\[5,6\],\[6,7\]\]  
**Output:** true  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg)**

  
**Input:** coordinates = \[\[1,1\],\[2,2\],\[3,4\],\[4,5\],\[5,6\],\[7,7\]\]  
**Output:** false  

**Constraints:**

*   `2 <= coordinates.length <= 1000`
*   `coordinates[i].length == 2`
*   `-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4`
*   `coordinates` contains no duplicate point.  



**Solution:**  

```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y = coordinates[0][1] - coordinates[1][1];
        double slope = y == 0 ? INT_MAX : 1.0 *(coordinates[0][0] - coordinates[1][0]) / y;
        for(int i = 2; i < coordinates.size(); ++i) {
            double dx = coordinates[i-1][0] - coordinates[i][0];
            double dy = coordinates[i-1][1] - coordinates[i][1];
            double sl = dy == 0 ? INT_MAX : dx / dy;
            if(fabs(sl - slope) > 0.000001) return false;
        }
        return true;
    }
};
```
      