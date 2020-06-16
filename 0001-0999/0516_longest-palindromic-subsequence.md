[516.longest-palindromic-subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)  

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

**Example 1:**  
Input:

  
"bbbab"  

Output:

  
4  

One possible longest palindromic subsequence is "bbbb".

**Example 2:**  
Input:

  
"cbbd"  

Output:

  
2  

One possible longest palindromic subsequence is "bb".

**Constraints:**

*   `1 <= s.length <= 1000`
*   `s` consists only of lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        bool dp[size+1][size+1] ={ 0 };
        int ans = 0;
        for( int i = size-1; i>=0; i-- ){
            for( int j = i; j<size; j++){
                if( s[i] == s[j] && (j-i<=1 || dp[i+1][j-1] )){
                    dp[i][j] = true;
                    ans = max( ans, j-i+1);
                }
            }   
        }
        return ans;
    }
};
```
      