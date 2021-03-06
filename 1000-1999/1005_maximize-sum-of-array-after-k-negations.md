[1005.maximize-sum-of-array-after-k-negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/)  

Given an array `A` of integers, we **must** modify the array in the following way: we choose an `i` and replace `A[i]` with `-A[i]`, and we repeat this process `K` times in total.  (We may choose the same index `i` multiple times.)

Return the largest possible sum of the array after modifying it in this way.

**Example 1:**

  
**Input:** A = \[4,2,3\], K = 1
  
**Output:** 5
  
**Explanation:** Choose indices (1,) and A becomes \[4,-2,3\].
  

**Example 2:**

  
**Input:** A = \[3,-1,0,2\], K = 3
  
**Output:** 6
  
**Explanation:** Choose indices (1, 2, 2) and A becomes \[3,1,0,2\].
  

**Example 3:**

  
**Input:** A = \[2,-3,-1,5,-4\], K = 2
  
**Output:** 13 **Explanation:** Choose indices (1, 4) and A becomes \[2,3,-1,5,4\].
  

**Note:**

1.  `1 <= A.length <= 10000`
2.  `1 <= K <= 10000`
3.  `-100 <= A[i] <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size() == 0) return 0;
        sort(A.begin(), A.end());
        int cnt = 0;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] < 0 && cnt < K) {
                A[i] = -A[i];
                ++cnt;
            }
        }
        sort(A.begin(), A.end());
        K -= cnt;
        if(K % 2) {
            A[0] = -A[0];
        }
        return accumulate(A.begin(), A.end(), 0);
    }
};
```
      