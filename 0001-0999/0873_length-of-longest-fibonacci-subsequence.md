[873.length-of-longest-fibonacci-subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)  

A sequence `X_1, X_2, ..., X_n` is _fibonacci-like_ if:

*   `n >= 3`
*   `X_i + X_{i+1} = X_{i+2}` for all `i + 2 <= n`

Given a **strictly increasing** array `A` of positive integers forming a sequence, find the **length** of the longest fibonacci-like subsequence of `A`.  If one does not exist, return 0.

(_Recall that a subsequence is derived from another sequence `A` by deleting any number of elements (including none) from `A`, without changing the order of the remaining elements.  For example, `[3, 5, 8]` is a subsequence of `[3, 4, 5, 6, 7, 8]`._)

**Example 1:**

**Input:** \[1,2,3,4,5,6,7,8\]
**Output:** 5
**Explanation:** The longest subsequence that is fibonacci-like: \[1,2,3,5,8\].

**Example 2:**

**Input:** \[1,3,7,11,12,14,18\]
**Output:** 3
**Explanation**:
The longest subsequence that is fibonacci-like:
\[1,11,12\], \[3,11,14\] or \[7,11,18\].

**Note:**

*   `3 <= A.length <= 1000`
*   `1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9`
*   _(The time limit has been reduced by 50% for submissions in Java, C, and C++.)_  



**Solution:**  

```cpp
class Solution {
public:
    /*int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_set<int> dict(A.begin(), A.end());
        int ans = 0;
        for( int i = 0; i<n; i++){
            int cnt = 0;
            
            for( int j = i+1; j<n; j++){
                int n2 = A[i];
                int n1 = A[j];
                int cnt = 0;
                while( dict.count(n1+n2) ){
                    cnt = cnt==0?3:cnt+1;
                    int cur = n1+n2;
                    n2 = n1;
                    n1 = cur;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }*/
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> dict;
        
        int n  = A.size();
        vector< vector<int> > dp(n, vector<int>(n,2));
        for( int i = 0; i<n; i++){
            dict[A[i]] = i;
        }
        int max_cnt = 0;
        int ans = 0;
        for( int i = 0; i<n; i++){
            int n1 = A[i];
            for( int j = i+1; j<n; j++){
                int n2 = A[j];
                int prev = n2-n1;
                if( dict.find(n2-n1) != dict.end() && dict[prev] < i ){
                    dp[i][j] = dp[dict[prev]][i] + 1;
                    
                }
                ans = max(dp[i][j], ans);
            }
        }
        return ans>2?ans:0;
    }
    
};
```
      