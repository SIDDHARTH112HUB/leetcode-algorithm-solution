[891.sum-of-subsequence-widths](https://leetcode.com/problems/sum-of-subsequence-widths/)  

Given an array of integers `A`, consider all non-empty subsequences of `A`.

For any sequence S, let the _width_ of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, **return the answer modulo 10^9 + 7**.

**Example 1:**

**Input:** \[2,1,3\]
**Output:** 6
**Explanation:** Subsequences are \[1\], \[2\], \[3\], \[2,1\], \[2,3\], \[1,3\], \[2,1,3\].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.

**Note:**

*   `1 <= A.length <= 20000`
*   `1 <= A[i] <= 20000`  



**Solution:**  

```cpp
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        long long M = 1000000007, c = 1,ans = 0;
        int n = A.size();
        for( int i = 0; i < A.size(); i++ ){
            ans = (ans + ( (A[i] - (A[n-i-1]) )*c+M)%M)%M;
            c = (c<< 1)%M;
        }
        return (ans+M) % M;
    }
};
```
      