[795.number-of-subarrays-with-bounded-maximum](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)  

We are given an array `A` of positive integers, and two positive integers `L` and `R` (`L <= R`).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least `L` and at most `R`.

**Example :**
**Input:** 
A = \[2, 1, 4, 3\]
L = 2
R = 3
**Output:** 3
**Explanation:** There are three subarrays that meet the requirements: \[2\], \[2, 1\], \[3\].

**Note:**

*   L, R  and `A[i]` will be an integer in the range `[0, 10^9]`.
*   The length of `A` will be in the range of `[1, 50000]`.  



**Solution:**  

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans= 0;
        for( int i = 0 ; i<A.size(); i++){
            int max = 0;
            for( int j =i; j<A.size(); j++){
                int num = A[j];
                if( max < num )
                    max = num;
                if( max >=L && max<=R ){
                    //printf("%d %d %d\n", max, num, ans);
                    ans++;
                }else{
                    //printf("break;\n");
                    continue;
                }
            }
        }
        return ans;
    }
};
```
      