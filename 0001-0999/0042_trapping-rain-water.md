[42.trapping-rain-water](https://leetcode.com/problems/trapping-rain-water/)  

Given _n_ non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)  
The above elevation map is represented by array \[0,1,0,2,1,0,1,3,2,1,2,1\]. In this case, 6 units of rain water (blue section) are being trapped. **Thanks Marcos** for contributing this image!

**Example:**

  
**Input:** \[0,1,0,2,1,0,1,3,2,1,2,1\]
  
**Output:** 6  



**Solution:**  

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if( height.size() <= 2 ) return 0;
        int ans = 0;
        int limit = 0, low = 0, l = 0, r = height.size()-1;
        while( l < r){
            low = height[l]< height[r]? height[l++]:height[r--];
            limit = max(limit, low);
            ans += limit - low;
        }
        return ans;
    }
};
```
      