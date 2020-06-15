[624.maximum-distance-in-arrays](https://leetcode.com/problems/maximum-distance-in-arrays/)  

Given `m` arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers `a` and `b` to be their absolute difference `|a-b|`. Your task is to find the maximum distance.

**Example 1:**  

**Input:** 
\[\[1,2,3\],
 \[4,5\],
 \[1,2,3\]\]
**Output:** 4
**Explanation:** 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

**Note:**  

1.  Each given array will have at least 1 number. There will be at least two non-empty arrays.
2.  The total number of the integers in **all** the `m` arrays will be in the range of \[2, 10000\].
3.  The integers in the `m` arrays will be in the range of \[-10000, 10000\].  



**Solution:**  

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if(arrays.size() == 0) return 0;
        int mn = arrays[0][0], mx = arrays[0].back();
        int ans = INT_MIN;
        for(int i = 1; i < arrays.size(); ++i) {
            ans = max(ans, max(abs(arrays[i].back() - mn), abs(arrays[i][0] - mx)) );
            mx = max(mx, arrays[i].back());
            mn = min(mn, arrays[i][0]);
        }
        return ans;
    }
};
```
      