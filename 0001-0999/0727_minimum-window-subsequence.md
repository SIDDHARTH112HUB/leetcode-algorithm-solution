[727.minimum-window-subsequence](https://leetcode.com/problems/minimum-window-subsequence/)  

Given strings `S` and `T`, find the minimum (contiguous) **substring** `W` of `S`, so that `T` is a **subsequence** of `W`.

If there is no such window in `S` that covers all characters in `T`, return the empty string `""`. If there are multiple such minimum-length windows, return the one with the left-most starting index.

**Example 1:**

**Input:** 
S = "abcdebdde", T = "bde"
**Output:** "bcde"
**Explanation:** 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.

**Note:**

*   All the strings in the input will only contain lowercase letters.
*   The length of `S` will be in the range `[1, 20000]`.
*   The length of `T` will be in the range `[1, 100]`.  



**Solution:**  

```cpp
class Solution {
public:
    /*
    int len = INT_MAX, idx = -1;
    string minWindow(string S, string T) {
        int dp[S.size()+1][T.size()+1];
        memset(dp, -1, sizeof(dp));
        string ans;
        for(int i = 0; i <= S.size(); ++i) {
            dp[i][0] = i;
        }
        int n  = T.size();
        for(int i = 1; i <= S.size(); ++i) {
            for(int j = 1; j <= min(i, (int)T.size()); ++j) {
                dp[i][j] = (S[i-1] == T[j-1] ? dp[i-1][j-1] : dp[i-1][j]);
                
            }
            if(dp[i][n] != -1) {
                int len = i - dp[i][n];
                auto str = S.substr(dp[i][n], len);
                if(ans == "" || ans.size() > str.size())
                    ans = str;
                    
            }
        }
        return ans;
    }*/
    string ans;
    int dp[20000][100];
    string minWindow(string S, string T) {
        memset(dp, -1, sizeof(dp));
        dfs(S, T, 0, 0);
        return ans;
    }
    int dfs(string &s, string &t, int i, int j) {
        if(t.size() == j) return i;
        if(s.size() == i) return i + 1;
        if(dp[i][j] >= 0) return dp[i][j];
        int last = s.size() + 1;
        if(s[i] == t[j])
            last = dfs(s, t, i + 1, j + 1);
        last = min(last, dfs(s, t, i + 1, j));
        if(j == 0 && last <= s.size() && (ans.size() == 0 || last - i <= ans.size())) {
            ans = s.substr(i, last - i);
        }
        return dp[i][j] = last;
    }
};
```
      