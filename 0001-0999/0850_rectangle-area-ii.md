[850.rectangle-area-ii](https://leetcode.com/problems/rectangle-area-ii/)  

We are given a list of (axis-aligned) `rectangles`.  Each `rectangle[i] = [x1, y1, x2, y2]` , where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the `i`th rectangle.

Find the total area covered by all `rectangles` in the plane.  Since the answer may be too large, **return it modulo 10^9 + 7**.

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/06/rectangle_area_ii_pic.png)

**Example 1:**

**Input:** \[\[0,0,2,2\],\[1,0,2,3\],\[1,0,3,1\]\]
**Output:** 6
**Explanation:** As illustrated in the picture.

**Example 2:**

**Input:** \[\[0,0,1000000000,1000000000\]\]
**Output:** 49
**Explanation:** The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 = (-7)^2 = 49.

**Note:**

*   `1 <= rectangles.length <= 200`
*   `rectanges[i].length = 4`
*   `0 <= rectangles[i][j] <= 10^9`
*   The total area covered by all rectangles will never exceed `2^63 - 1` and thus will fit in a 64-bit signed integer.  



**Solution:**  

```cpp
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rs) {
        set<int> xs, ys;
        for(auto &r : rs) {
            xs.insert(r[0]);
            xs.insert(r[2]);
            ys.insert(r[1]);
            ys.insert(r[3]);
        }
        vector<int> ix(xs.begin(), xs.end());
        vector<int> iy(ys.begin(), ys.end());
        unordered_map<int, int> xm, ym;
        int idx = 0;
        for(auto n : xs) {
            xm[n] = idx++;
        }
        idx = 0;
        for(auto n : ys) {
            ym[n] = idx++;
        }
        bool grid[xs.size()+1][ys.size()+1];
        memset(grid, 0, sizeof(grid));
        for(auto &r : rs) {
            for(int i = xm[r[0]]; i < xm[r[2]]; ++i) {
                for(int j = ym[r[1]]; j < ym[r[3]]; ++j) {
                    grid[i][j] = true;
                }
            }
        }
        int i = 0, j = 0;
        long long ans = 0;
        for(int i = 0; i < xs.size(); ++i) {
            for(int j = 0; j < ys.size(); ++j) {
                if(grid[i][j] == true) {
                    ans += (long long)(ix[i + 1] - ix[i])  * (long long)(iy[j+1] - iy[j]);
                }
            }
        }
        return ans % 1000000007;
    }
};
```
      