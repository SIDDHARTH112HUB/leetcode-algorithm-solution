[1027.longest-arithmetic-sequence](https://leetcode.com/problems/longest-arithmetic-sequence/)  

Given an array `A` of integers, return the **length** of the longest arithmetic subsequence in `A`.

Recall that a _subsequence_ of `A` is a list `A[i_1], A[i_2], ..., A[i_k]` with `0 <= i_1 < i_2 < ... < i_k <= A.length - 1`, and that a sequence `B` is _arithmetic_ if `B[i+1] - B[i]` are all the same value (for `0 <= i < B.length - 1`).

**Example 1:**

**Input:** \[3,6,9,12\]
**Output:** 4
**Explanation:** 
The whole array is an arithmetic sequence with steps of length = 3.

**Example 2:**

**Input:** \[9,4,7,2,10\]
**Output:** 3
**Explanation:** 
The longest arithmetic subsequence is \[4,7,10\].

**Example 3:**

**Input:** \[20,1,15,3,10,5,8\]
**Output:** 4
**Explanation:** 
The longest arithmetic subsequence is \[20,15,10,5\].

**Note:**

1.  `2 <= A.length <= 2000`
2.  `0 <= A[i] <= 10000`  



**Solution:**  

```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size() <= 0) return A.size();
        vector<unordered_map<int, int> > m(A.size());
        int ans = 1;
        for(int i = 0; i < A.size(); ++i) {
            int a = A[i];
            for(int j = 0; j < i; ++j) {
                int b = A[j];
                int diff = a - b;
                if(m[j].count(diff))
                    m[i][diff] = max(m[i][diff], 1 + m[j][diff]);
                else
                    m[i][diff] = 2;
                ans = max(ans, m[i][diff]);
            }
        }
        return ans;
    }
};
```
      