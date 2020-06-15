[930.binary-subarrays-with-sum](https://leetcode.com/problems/binary-subarrays-with-sum/)  

In an array `A` of `0`s and `1`s, how many **non-empty** subarrays have sum `S`?

**Example 1:**

**Input:** A = \[1,0,1,0,1\], S = 2
**Output:** 4
**Explanation:** 
The 4 subarrays are bolded below:
\[**1,0,1**,0,1\]
\[**1,0,1,0**,1\]
\[1,**0,1,0,1**\]
\[1,0,**1,0,1**\]

**Note:**

1.  `A.length <= 30000`
2.  `0 <= S <= A.length`
3.  `A[i]` is either `0` or `1`.  



**Solution:**  

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int m[A.size()+1] = {0};
        m[0] = 1;
        int psum = 0;
        int res = 0;
        for( auto n : A ){
            psum += n;
            if( psum >= S )
                res += m[psum - S ];
            m[psum]++;
        }
        return res;
    }
};
```
      