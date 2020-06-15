[1187.make-array-strictly-increasing](https://leetcode.com/problems/make-array-strictly-increasing/)  

Given two integer arrays `arr1` and `arr2`, return the minimum number of operations (possibly zero) needed to make `arr1` strictly increasing.

In one operation, you can choose two indices `0 <= i < arr1.length` and `0 <= j < arr2.length` and do the assignment `arr1[i] = arr2[j]`.

If there is no way to make `arr1` strictly increasing, return `-1`.

**Example 1:**

**Input:** arr1 = \[1,5,3,6,7\], arr2 = \[1,3,2,4\]
**Output:** 1
**Explanation:** Replace `5` with `2`, then `arr1 = [1, 2, 3, 6, 7]`.

**Example 2:**

**Input:** arr1 = \[1,5,3,6,7\], arr2 = \[4,3,1\]
**Output:** 2
**Explanation:** Replace `5` with `3` and then replace `3` with `4`. `arr1 = [1, 3, 4, 6, 7]`.

**Example 3:**

**Input:** arr1 = \[1,5,3,6,7\], arr2 = \[1,6,3,3\]
**Output:** -1
**Explanation:** You can't make `arr1` strictly increasing.

**Constraints:**

*   `1 <= arr1.length, arr2.length <= 2000`
*   `0 <= arr1[i], arr2[i] <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int dp[2001][2001] = {0};
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int res = dfs(arr1, arr2, 0, 0, INT_MIN);
        return res >= 3000 ? -1 : res;
    }
    
    int dfs(vector<int>& arr1, vector<int>& arr2, int i, int j, int prev) {
        if(i >= arr1.size()) return 0;
        j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
        if(dp[i][j] > 0) return dp[i][j] - 1;
        int res = 3000;
        if(j < arr2.size())
            res = 1 + dfs(arr1, arr2, i + 1, j, arr2[j] );
        if(arr1[i] > prev)
            res = min(res, dfs(arr1, arr2, i + 1, j, arr1[i]));
        dp[i][j] = res + 1;
        return res;
    }
};
```
      