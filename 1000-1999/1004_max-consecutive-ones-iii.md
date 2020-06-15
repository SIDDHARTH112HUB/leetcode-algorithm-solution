[1004.max-consecutive-ones-iii](https://leetcode.com/problems/max-consecutive-ones-iii/)  

Given an array `A` of 0s and 1s, we may change up to `K` values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

**Example 1:**

**Input:** A = \[1,1,1,0,0,0,1,1,1,1,0\], K = 2
**Output:** 6
**Explanation:** 
\[1,1,1,0,0,**1**,1,1,1,1,**1**\]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

**Example 2:**

**Input:** A = \[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1\], K = 3
**Output:** 10
**Explanation:** 
\[0,0,1,1,**1**,**1**,1,1,1,**1**,1,1,0,0,0,1,1,1,1\]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

**Note:**

1.  `1 <= A.length <= 20000`
2.  `0 <= K <= A.length`
3.  `A[i]` is `0` or `1`  



**Solution:**  

```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, k = 0;
        int ans = 0;
        while(j< A.size() && i <= j) {
            ans = max(j - i, ans);
            if(A[j] == 0) {
                k++;
                while(i < A.size() && k > K){
                    if(A[i] == 0)k--;
                    i++;
                }
            }
            j++;
        }
        ans = max(j - i, ans);
        return ans;
    }
};
```
      