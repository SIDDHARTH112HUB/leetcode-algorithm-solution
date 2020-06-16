[812.largest-triangle-area](https://leetcode.com/problems/largest-triangle-area/)  

You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

  
**Example:**
  
**Input:** points = \[\[0,0\],\[0,1\],\[1,0\],\[0,2\],\[2,0\]\]
  
**Output:** 2
  
**Explanation:** 
  
The five points are show in the figure below. The red triangle is the largest.
  

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/04/1027.png)

**Notes:**

*   `3 <= points.length <= 50`.
*   No points will be duplicated.
*    `-50 <= points[i][j] <= 50`.
*   Answers within `10^-6` of the true value will be accepted as correct.  



**Solution:**  

```cpp
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int size = points.size();
        double ans = 0;
        for( int i = 0; i<size; i++){
            for( int j = i+1; j<size; j++){
                for( int k = j+1; k<size; k++){
                    auto &A = points[i];
                    auto &B = points[j];
                    auto &C = points[k];
                    double area = fabs( ( A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1]))/2.0 );
                    if( area > ans )
                        ans = area;
                }
            }
        }
        return ans;
    }
};
```
      