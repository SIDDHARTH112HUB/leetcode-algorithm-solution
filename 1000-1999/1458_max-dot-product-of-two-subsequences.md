[1458.max-dot-product-of-two-subsequences](https://leetcode.com/problems/max-dot-product-of-two-subsequences/)  

Given two arrays `nums1` and `nums2`.

Return the maximum dot product between **non-empty** subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `[2,3,5]` is a subsequence of `[1,2,3,4,5]` while `[1,5,3]` is not).

**Example 1:**

  
**Input:** nums1 = \[2,1,-2,5\], nums2 = \[3,0,-6\]  
**Output:** 18  
**Explanation:** Take subsequence \[2,-2\] from nums1 and subsequence \[3,-6\] from nums2.  
Their dot product is (2\*3 + (-2)\*(-6)) = 18.

**Example 2:**

  
**Input:** nums1 = \[3,-2\], nums2 = \[2,-6,7\]  
**Output:** 21  
**Explanation:** Take subsequence \[3\] from nums1 and subsequence \[7\] from nums2.  
Their dot product is (3\*7) = 21.

**Example 3:**

  
**Input:** nums1 = \[-1,-1\], nums2 = \[1,1\]  
**Output:** -1  
**Explanation:** Take subsequence \[-1\] from nums1 and subsequence \[1\] from nums2.  
Their dot product is -1.

**Constraints:**

*   `1 <= nums1.length, nums2.length <= 500`
*   `-1000 <= nums1[i], nums2[i] <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > dp;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return dfs(nums1, nums2, 0, 0);
    }
    
    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i >= nums1.size()) return -10000000;
        if(j >= nums2.size()) return -10000000;
        if(dp[i].count(j)) return dp[i][j];
        int ret = dfs(nums1, nums2, i + 1, j+ 1);
        int res = max(nums1[i] * nums2[j], ret + nums1[i] * nums2[j]);
        res = max(res , dfs(nums1, nums2, i, j+ 1));
        res = max(res , dfs(nums1, nums2, i + 1, j));
        return dp[i][j] =res;
    }
};
```
      