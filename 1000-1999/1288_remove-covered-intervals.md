[1288.remove-covered-intervals](https://leetcode.com/problems/remove-covered-intervals/)  

Given a list of intervals, remove all intervals that are covered by another interval in the list. Interval `[a,b)` is covered by interval `[c,d)` if and only if `c <= a` and `b <= d`.

After doing so, return the number of remaining intervals.

**Example 1:**

**Input:** intervals = \[\[1,4\],\[3,6\],\[2,8\]\]
**Output:** 2
**Explanation:** Interval \[3,6\] is covered by \[2,8\], therefore it is removed.

**Constraints:**

*   `1 <= intervals.length <= 1000`
*   `0 <= intervals[i][0] < intervals[i][1] <= 10^5`
*   `intervals[i] != intervals[j]` for all `i != j`  



**Solution:**  

```cpp
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int idx = 1; idx < intervals.size(); ++idx) {
            auto &i = intervals[idx];
            if(i[1] <= end){
                continue;
            }else {
                ++ans;
                end = i[1];
                start = i[0];
            }
        }
        return ans;
    }
};
```
      