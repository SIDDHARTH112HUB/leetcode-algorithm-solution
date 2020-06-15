[84.largest-rectangle-in-histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)  

Given _n_ non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

![](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)  
Above is a histogram where width of each bar is 1, given height = `[2,1,5,6,2,3]`.

![](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)  
The largest rectangle is shown in the shaded area, which has area = `10` unit.

**Example:**

**Input:** \[2,1,5,6,2,3\]
**Output:** 10  



**Solution:**  

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        auto &h = heights;
        int ans = 0;
        h.push_back(-1);
        stack<pair<int, int> > stk;
        for( int i = 0; i<h.size(); i++){
            while( stk.size() && stk.top().first > h[i]){
                int prev_h = stk.top().first;
                stk.pop();    
                int prev_idx = 0;
                if( stk.size() )
                    prev_idx = stk.top().second+1;
                ans = max( prev_h *(i-prev_idx), ans);
            }
            stk.push({h[i], i});
        }
        h.pop_back();
        return ans;
    }
};
```
      