[903.valid-permutations-for-di-sequence](https://leetcode.com/problems/valid-permutations-for-di-sequence/)  

We are given `S`, a length `n` string of characters from the set `{'D', 'I'}`. (These letters stand for "decreasing" and "increasing".)

A _valid permutation_ is a permutation `P[0], P[1], ..., P[n]` of integers `{0, 1, ..., n}`, such that for all `i`:

*   If `S[i] == 'D'`, then `P[i] > P[i+1]`, and;
*   If `S[i] == 'I'`, then `P[i] < P[i+1]`.

How many valid permutations are there?  Since the answer may be large, **return your answer modulo `10^9 + 7`**.

**Example 1:**

  
**Input:** "DID"
  
**Output:** 5
  
**Explanation:** 
  
The 5 valid permutations of (0, 1, 2, 3) are:
  
(1, 0, 3, 2)
  
(2, 0, 3, 1)
  
(2, 1, 3, 0)
  
(3, 0, 2, 1)
  
(3, 1, 2, 0)
  

**Note:**

1.  `1 <= S.length <= 200`
2.  `S` consists only of characters from the set `{'D', 'I'}`.  



**Solution:**  

```cpp
class Solution {
public:
    int numPermsDISequence(string S) {
        int M = 1000000007;
        int N = S.size();
        long long dp[N+1][N+1] = {0};
        dp[0][0] = 1;
        for( int i = 1; i<=N; i++){
            for( int j = 0; j<=i; j++){
                if( S[i-1] == 'D'){
                    for( int k = j; k <= i-1; k++){
                        dp[i][j] += dp[i-1][k];
                    }
                }else{
                    for( int k = 0; k<j; k++){
                        dp[i][j]+= dp[i-1][k];
                    }
                }
                dp[i][j] %= M;
            }
            
        }
        long long res = 0;
        for( int i = 0; i<=N; i++)
            res = (res + dp[N][i])%M;
        return res;
    }
};
```
      