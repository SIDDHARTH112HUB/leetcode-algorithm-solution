[786.k-th-smallest-prime-fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/)  

A sorted list `A` contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the `K`\-th smallest fraction considered?  Return your answer as an array of ints, where `answer[0] = p` and `answer[1] = q`.

**Examples:**
**Input:** A = \[1, 2, 3, 5\], K = 3
**Output:** \[2, 5\]
**Explanation:**
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

**Input:** A = \[1, 7\], K = 1
**Output:** \[1, 7\]

**Note:**

*   `A` will have length between `2` and `2000`.
*   Each `A[i]` will be between `1` and `30000`.
*   `K` will be between `1` and `A.length * (A.length - 1) / 2`.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l = 0, r = 1.0;
        int n = A.size();
        while(l < r) {
            double mid = (l + r) / 2;
            int num = 0, ii, jj;
            double mf = 0.0, max_f = 0.0;
            int j = 0;
            for(int i = 0; i < A.size() - 1; ++i) {
                while(j < A.size() && A[i] * 1.0 / A[j] > mid ) {
                    ++j;
                }
                if(j < A.size()){
                    double t = A[i] * 1.0 / A[j]; 
                    if (t > mf) {
                        mf = t;
                        ii = A[i];
                        jj = A[j];
                    }
                }
                num += n - j;
            }
            if(num == K) {
                
                return {ii, jj};
            }
            else if(num > K)
                r = mid;
            else
                l = mid;
                
        }
        return {};
    }
};
```
      