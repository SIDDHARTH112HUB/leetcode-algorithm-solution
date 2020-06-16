[1043.partition-array-for-maximum-sum](https://leetcode.com/problems/partition-array-for-maximum-sum/)  

Given an integer array `A`, you partition the array into (contiguous) subarrays of length at most `K`.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

**Example 1:**

  
**Input:** A = \[1,15,7,9,2,5,10\], K = 3
  
**Output:** 84 **Explanation**: A becomes \[15,15,15,9,10,10,10\]

**Note:**

1.  `1 <= K <= A.length <= 500`
2.  `0 <= A[i] <= 10^6`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > m;
    int maxSumAfterPartitioning(vector<int>& A, int K) {
       return solve(A, 0, K);
    }
    
    int solve(vector<int>& A, int idx, int K) {
        if (idx == A.size())
            return 0;
        if (m[idx].count(K))
            return m[idx][K];
        
        
        int mx = 0;
        int ans = 0;
        for( int i = idx; i < A.size() && i < idx+K; ++i) {
            mx = max(mx, A[i]);
            ans = max(ans, mx * (i - idx+1) + solve(A, i + 1, K));
        }
        m[idx][K] = ans;
        return ans;
    }
};
```
      