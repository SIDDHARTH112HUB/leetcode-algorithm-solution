[1092.shortest-common-supersequence](https://leetcode.com/problems/shortest-common-supersequence/)  

Given two strings `str1` and `str2`, return the shortest string that has both `str1` and `str2` as subsequences.  If multiple answers exist, you may return any of them.

_(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)_

**Example 1:**

**Input:** str1 = "abac", str2 = "cab"
**Output:** "cabac"
**Explanation:** 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

**Note:**

1.  `1 <= str1.length, str2.length <= 1000`
2.  `str1` and `str2` consist of lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m = X.size(), n = Y.size();
        int L[X.size()+1][Y.size()+1] = {0};
        for (int i=0; i<=m; i++) 
        {
            for (int j=0; j<=n; j++) 
            { 
                if (i == 0 || j == 0) 
                    L[i][j] = 0; 
                else if (X[i-1] == Y[j-1])
                    L[i][j] = L[i-1][j-1] + 1; 
                else
                    L[i][j] = max(L[i-1][j], L[i][j-1]); 
            }
        }
        int i = m, j = n; 
        string ans = "";
        int i1 = m-1, i2 = n-1;
        while (i > 0 && j > 0) 
        {
            if (X[i-1] == Y[j-1]) 
            {
                char c = X[i-1];
                while(i1 >= 0 && X[i1] != c)
                    ans.push_back(X[i1--]);
                i1--;
                while(i2 >= 0 && Y[i2] != c)
                    ans.push_back(Y[i2--]);
                i2--;
                ans.push_back(c);
                i--; j--;
            }
            else if (L[i-1][j] > L[i][j-1]) 
                i--;
            else
                j--; 
        }
        
        while(i1 >= 0)
            ans.push_back(X[i1--]);
        while(i2 >= 0)
            ans.push_back(Y[i2--]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      