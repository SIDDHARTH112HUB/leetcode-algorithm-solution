[1035.uncrossed-lines](https://leetcode.com/problems/uncrossed-lines/)  

We write the integers of `A` and `B` (in the order they are given) on two separate horizontal lines.

Now, we may draw _connecting lines_: a straight line connecting two numbers `A[i]` and `B[j]` such that:

*   `A[i] == B[j]`;
*   The line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/04/26/142.png)

  
**Input:** A = \[1,4,2\], B = \[1,2,4\]
  
**Output:** 2
  
**Explanation:** We can draw 2 uncrossed lines as in the diagram.
  
We cannot draw 3 uncrossed lines, because the line from A\[1\]=4 to B\[2\]=4 will intersect the line from A\[2\]=2 to B\[1\]=2.
  

**Example 2:**

  
**Input:** A = \[2,5,1,2,5\], B = \[10,5,2,1,5,2\]
  
**Output:** 3
  

**Example 3:**

  
**Input:** A = \[1,3,7,1,7,5\], B = \[1,9,2,5,1\]
  
**Output:** 2

**Note:**

1.  `1 <= A.length <= 500`
2.  `1 <= B.length <= 500`
3.  `1 <= A[i], B[i] <= 2000`  



**Solution:**  

```cpp
class Solution {
public:
    int dp[500][500];
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof(dp));
        return dfs(A, B, 0, 0);
        for(int i = 0; i < A.size(); ++i) 
            for(int j = 0; j < B.size(); ++j) 
                if(A[i] == B[j]) dp[i][j] = max(dp[i][j], (i > 0 && j > 0 ? dp[i-1][j-1] : 0) + 1);
                else dp[i][j] = max(j > 0 ? dp[i][j-1]:0, i > 0 ? dp[i-1][j] : 0);
        return dp[A.size()-1][B.size()-1];
    }
    
    int dfs(vector<int>& A, vector<int>& B, int i, int j) {
        if(A.size() <= i) return 0;
        if(B.size() <= j) return 0;
        if(dp[i][j] >= 0) return dp[i][j];
        return dp[i][j] = A[i] == B[j] ? (1 + dfs(A, B, i + 1, j + 1)) : max(dfs(A, B, i + 1, j), dfs(A, B, i, j + 1));
    }
};
```
      