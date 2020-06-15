[730.count-different-palindromic-subsequences](https://leetcode.com/problems/count-different-palindromic-subsequences/)  

Given a string S, find the number of different non-empty palindromic subsequences in S, and **return that number modulo `10^9 + 7`.**

A subsequence of a string S is obtained by deleting 0 or more characters from S.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences `A_1, A_2, ...` and `B_1, B_2, ...` are different if there is some `i` for which `A_i != B_i`.

**Example 1:**  

**Input:** 
S = 'bccb'
**Output:** 6
**Explanation:** 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.

**Example 2:**  

**Input:** 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
**Output:** 104860361
**Explanation:** 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.

**Note:**

*   The length of `S` will be in the range `[1, 1000]`.
*   Each character `S[i]` will be in the set `{'a', 'b', 'c', 'd'}`.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > memo;
    int M = 1e+9+7;
    int countPalindromicSubsequences(string S) {
        return dfs(S, 0, S.size()-1);
    }
    
    int dfs(string &s, int i , int j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(memo[i].count(j)) return memo[i][j];
        int res = 0;
        if(s[i] != s[j]) {
            res = ((dfs(s, i+1, j) + dfs(s, i, j-1))%M + (M - dfs(s, i +1, j - 1))%M) %M;
        }else{
            int a = i + 1, b = j -1;
            while(a < j && s[i] != s[a])
                ++a;
            while(b > i && s[i] != s[b])
                --b;
            if(b > a) {
                res = (dfs(s, i+1, j-1) * 2)%M  + (M- dfs(s, a+1, b-1))%M;
            }else{
                res = (dfs(s, i+1, j-1) * 2 ) %M + (b == a ? 1 : 2);
            }
        
        }
        memo[i][j] = res %M;
        return res %M;
    }
};
```
      