[1397.find-all-good-strings](https://leetcode.com/problems/find-all-good-strings/)  

Given the strings `s1` and `s2` of size `n`, and the string `evil`. _Return the number of **good** strings_.

A **good** string has size `n`, it is alphabetically greater than or equal to `s1`, it is alphabetically smaller than or equal to `s2`, and it does not contain the string `evil` as a substring. Since the answer can be a huge number, return this modulo 10^9 + 7.

**Example 1:**

  
**Input:** n = 2, s1 = "aa", s2 = "da", evil = "b"  
**Output:** 51   
**Explanation:** There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da".   

**Example 2:**

  
**Input:** n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"  
**Output:** 0   
**Explanation:** All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.  

**Example 3:**

  
**Input:** n = 2, s1 = "gx", s2 = "gz", evil = "x"  
**Output:** 2  

**Constraints:**

*   `s1.length == n`
*   `s2.length == n`
*   `s1 <= s2`
*   `1 <= n <= 500`
*   `1 <= evil.length <= 50`
*   All strings consist of lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    long long dp[501][51][2][2];
    vector<int> lps;
    int findGoodStrings(int n, string s1, string s2, string evil) {
        memset(dp, -1, sizeof(dp));
        lps = calLPS(evil);
        return solve(s1, s2, evil, 0, 0, true, true);
    }

    long long solve(string &s1, string &s2, string &evil, int i, int evilMatch, bool leftBound, bool rightBound) {
        if(evilMatch == evil.size()) return 0;
        if(i == s1.size()) return 1;
        if(dp[i][evilMatch][leftBound][rightBound] >= 0) return dp[i][evilMatch][leftBound][rightBound];
        char from = leftBound ? s1[i] : 'a';
        char to   = rightBound ? s2[i] : 'z';
        long long res = 0;
        for(int c = from; c<=to; ++c) {
            int j = evilMatch;
            while(j > 0 && c != evil[j]) j = lps[j-1];
            if(c == evil[j]) ++j;
            res += solve(s1, s2, evil, i + 1, j, leftBound && (c == from) , rightBound && ( c== to));
            res %= 1000000007;
        }
        dp[i][evilMatch][leftBound][rightBound] = res;
        return res;
    }
    vector<int> calLPS(string &s) {
        vector<int> lps(s.size());
        for(int i = 1, j = 0; i < s.size(); ++i) {
            while(j > 0 && s[i] != s[j]) j = lps[j-1];
            if(s[i] == s[j]) lps[i] = ++j;
        }
        return lps;
    }
};
```
      