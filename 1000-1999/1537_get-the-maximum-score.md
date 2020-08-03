[1537.get-the-maximum-score](https://leetcode.com/problems/get-the-maximum-score/)  

You are given two **sorted** arrays of distinct integers `nums1` and `nums2.`

A **valid path** is defined as follows:

*   Choose array nums1 or nums2 to traverse (from index-0).
*   Traverse the current array from left to right.
*   If you are reading any value that is present in `nums1` and `nums2` you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).

_Score_ is defined as the sum of uniques values in a valid path.

Return the maximum _score_ you can obtain of all possible **valid paths**.

Since the answer may be too large, return it modulo 10^9 + 7.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/07/16/sample_1_1893.png)**

  
**Input:** nums1 = \[2,4,5,8,10\], nums2 = \[4,6,8,9\]  
**Output:** 30  
**Explanation:** Valid paths:  
\[2,4,5,8,10\], \[2,4,5,8,9\], \[2,4,6,8,9\], \[2,4,6,8,10\],  (starting from nums1)  
\[4,6,8,9\], \[4,5,8,10\], \[4,5,8,9\], \[4,6,8,10\]    (starting from nums2)  
The maximum is obtained with the path in green **\[2,4,6,8,10\]**.  

**Example 2:**

  
**Input:** nums1 = \[1,3,5,7,9\], nums2 = \[3,5,100\]  
**Output:** 109  
**Explanation:** Maximum sum is obtained with the path **\[1,3,5,100\]**.  

**Example 3:**

  
**Input:** nums1 = \[1,2,3,4,5\], nums2 = \[6,7,8,9,10\]  
**Output:** 40  
**Explanation:** There are no common elements between nums1 and nums2.  
Maximum sum is obtained with the path \[6,7,8,9,10\].  

**Example 4:**

  
**Input:** nums1 = \[1,4,5,8,9,11,19\], nums2 = \[2,3,4,11,12\]  
**Output:** 61  

**Constraints:**

*   `1 <= nums1.length <= 10^5`
*   `1 <= nums2.length <= 10^5`
*   `1 <= nums1[i], nums2[i] <= 10^7`
*   `nums1` and `nums2` are strictly increasing.  



**Solution:**  

```cpp
typedef long long ll;
class Solution {
public:
    unordered_map<ll, ll> eqls[2];
    unordered_map<ll, ll> dp[2];
    ll dfs(vector<vector<ll> > &nums, int idx, bool AorB) {
        if(nums[AorB].size() <= idx) return 0;
        if(dp[AorB].count(idx)) return dp[AorB][idx];
        ll num = nums[AorB][idx];
        ll res = num+ dfs(nums, idx + 1, AorB);
        if(eqls[!AorB].count(num)) {
            res = max(res, num + dfs(nums, eqls[!AorB][num] + 1, !AorB));
        }
        return dp[AorB][idx] = res;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<ll, ll> m;
        vector<vector<ll> > nums(2);
        for(int i = 0; i < nums1.size(); ++i) {
            int n = nums1[i];
            m[n] = i;
            nums[0].push_back(n);
        }
        for(int i = 0; i < nums2.size(); ++i) {
            int n = nums2[i];
            nums[1].push_back(n);
            if(m.count(n)) {
                eqls[0][n] = m[n];
                eqls[1][n] = i;
            }
        }
        return max(dfs(nums, 0, 0), dfs(nums, 0, 1))%1000000007;
    }
};
```
      