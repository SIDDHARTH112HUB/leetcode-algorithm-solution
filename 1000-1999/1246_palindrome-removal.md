[1246.palindrome-removal](https://leetcode.com/problems/palindrome-removal/)  

Given an integer array `arr`, in one move you can select a **palindromic** subarray `arr[i], arr[i+1], ..., arr[j]` where `i <= j`, and remove that subarray from the given array. Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.

Return the minimum number of moves needed to remove all numbers from the array.

**Example 1:**

  
**Input:** arr = \[1,2\]  
**Output:** 2  

**Example 2:**

  
**Input:** arr = \[1,3,4,1,5\]  
**Output:** 3  
**Explanation:** Remove \[4\] then remove \[1,3,1\] then remove \[5\].  

**Constraints:**

*   `1 <= arr.length <= 100`
*   `1 <= arr[i] <= 20`  



**Solution:**  

```cpp
class Solution {
public:
    int dp[101][101];
    int minimumMoves(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return dfs(arr, 0, arr.size() - 1);
    }
    
    int dfs(vector<int>& arr, int l, int r) {
        if(l > r) return 0;
        if(l == r) return 1;
        if(r - l == 1) return (arr[l] != arr[r]) + 1;
        if(dp[l][r] >= 0) return dp[l][r];
        int res = INT_MAX;
        for(int i = l; i <= r; ++i) {
            if(arr[l] == arr[i] && l != i) {
                res = min(res, dfs(arr, l + 1, i - 1) + (i - l < 2 ? 1 :0) + dfs(arr, i + 1, r));
            }else
                res = min(res, dfs(arr, l, i - 1) + 1 + dfs(arr, i+1, r));
        }
        return dp[l][r] = res;
    }
};
```
      