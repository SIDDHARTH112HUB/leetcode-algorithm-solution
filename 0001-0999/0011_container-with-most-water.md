[11.container-with-most-water](https://leetcode.com/problems/container-with-most-water/)  

Given _n_ non-negative integers _a1_, _a2_, ..., _an_ , where each represents a point at coordinate (_i_, _ai_). _n_ vertical lines are drawn such that the two endpoints of line _i_ is at (_i_, _ai_) and (_i_, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

**Note:** You may not slant the container and _n_ is at least 2.

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

The above vertical lines are represented by array \[1,8,6,2,5,4,8,3,7\]. In this case, the max area of water (blue section) the container can contain is 49.

**Example:**

  
**Input:** \[1,8,6,2,5,4,8,3,7\]
  
**Output:** 49  



**Solution:**  

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        if( height.size() <= 1 ) return 0;
        int ans = 0;
        int l = 0, r=height.size()-1;
        while( l < r ){
            ans = max( ans, (r-l)*min(height[r], height[l]) );
            height[r] > height[l]?++l:--r;
        }
        return ans;
    }
};
```
      