[44.wildcard-matching](https://leetcode.com/problems/wildcard-matching/)  

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'`.

  
'?' Matches any single character.
  
'\*' Matches any sequence of characters (including the empty sequence).
  

The matching should cover the **entire** input string (not partial).

**Note:**

*   `s` could be empty and contains only lowercase letters `a-z`.
*   `p` could be empty and contains only lowercase letters `a-z`, and characters like `?` or `*`.

**Example 1:**

  
**Input:**
  
s = "aa"
  
p = "a"
  
**Output:** false
  
**Explanation:** "a" does not match the entire string "aa".
  

**Example 2:**

  
**Input:**
  
s = "aa"
  
p = "\*"
  
**Output:** true
  
**Explanation:** '\*' matches any sequence.
  

**Example 3:**

  
**Input:**
  
s = "cb"
  
p = "?a"
  
**Output:** false
  
**Explanation:** '?' matches 'c', but the second letter is 'a', which does not match 'b'.
  

**Example 4:**

  
**Input:**
  
s = "adceb"
  
p = "\*a\*b"
  
**Output:** true
  
**Explanation:** The first '\*' matches the empty sequence, while the second '\*' matches the substring "dce".
  

**Example 5:**

  
**Input:**
  
s = "acdcb"
  
p = "a\*c?b"
  
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    //bool dp[2000];
    
    bool isMatch(string s, string p){
        //memset(dp, true, sizeof(dp));
        //return isMatch2(s, p, 0, 0);
        int dp[s.size()+1][p.size()+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for( int i = 0; i<p.size(); i++){
            if( p[i] == '*')
                dp[0][i+1] = dp[0][i];
        }
        for( int i =1; i<=s.size(); i++){
            for( int j = 1; j<=p.size(); j++){
                if( p[j-1] == '*')
                    dp[i][j] = dp[i][j-1]|| dp[i-1][j];
                else
                    dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='?') && dp[i-1][j-1];
            }
        }
        return dp[s.size()][p.size()];
    }
    /*bool isMatch2(string &s, string &p, int si, int pi) {
        if( dp[si] == false) return false;
        
        while( si < s.size() || pi < p.size() ){
            if( si == s.size() && p[pi] != '*')
                return false;
            if( pi == p.size() && si <s.size() )
                return false;
            if( p[pi]=='?' || s[si] == p[pi] ){
                si++;
                pi++;
            }else if( p[pi] == '*'){
                for( int i = si; i<=s.size(); i++){
                    bool res = isMatch2(s, p, i, pi+1);
                    if( res == true )
                        return true;
                    dp[i] = false;
                }
                return false;
            }else
                return false;
        }
        return true;
    }*/
    
};
```
      