[813.largest-sum-of-averages](https://leetcode.com/problems/largest-sum-of-averages/)  

We partition a row of numbers `A` into at most `K` adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

  
**Example:**
  
**Input:** 
  
A = \[9,1,2,3,9\]
  
K = 3
  
**Output:** 20
  
**Explanation:** 
  
The best choice is to partition A into \[9\], \[1, 2, 3\], \[9\]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
  
We could have also partitioned A into \[9, 1\], \[2\], \[3, 9\], for example.
  
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
  

**Note:**

*   `1 <= A.length <= 100`.
*   `1 <= A[i] <= 10000`.
*   `1 <= K <= A.length`.
*   Answers within `10^-6` of the correct answer will be accepted as correct.  



**Solution:**  

```cpp
class Solution {
public:
    double dp[201][201] = {0};
    
    double largestSumOfAverages(vector<int>& A, int K) {
        return search(A, A.size(), K);
    }
    
    double search(vector<int>& A, int n, int k) {
        if( dp[n][k] != 0 ) return dp[n][k];
        if (n < k ) return 0;
        if (k == 1) {
            return accumulate(A.begin(), A.begin()+n, 0) * 1.0 / n;
        }
        double cur = 0;
        for (int i = n-1; i >= 0; i--){
            cur += A[i];
            dp[n][k] = max(dp[n][k], search(A, i, k-1) + cur / (n-i) );
        }
        return dp[n][k];
    }
};
```
      