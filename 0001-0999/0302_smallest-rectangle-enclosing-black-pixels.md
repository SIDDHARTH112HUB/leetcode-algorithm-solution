[302.smallest-rectangle-enclosing-black-pixels](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/)  

An image is represented by a binary matrix with `0` as a white pixel and `1` as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location `(x, y)` of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

**Example:**

**Input:**
\[
  "0010",
  "0110",
  "0100"
\]
and `x = 0,` `y = 2`

**Output:** 6  



**Solution:**  

```cpp
class Solution {
public:
    int mnx = INT_MAX;
    int mny = INT_MAX;
    int mxx = 0;
    int mxy = 0;
    int minArea(vector<vector<char>>& image, int x, int y) {
        dfs(image, x, y);
        return (mxx - mnx+1) * (mxy - mny+1);
    }
    
    void dfs(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || image[x][y] == '0') return;
        mnx = min(x, mnx); mny = min(y, mny);
        mxx = max(x, mxx); mxy = max(y, mxy);
        image[x][y] = '0';
        dfs(image, x + 1, y);
        dfs(image, x, y + 1);
        dfs(image, x, y - 1);
        dfs(image, x - 1, y);
    }
};
```
      