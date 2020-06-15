[1444.number-of-ways-of-cutting-a-pizza](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/)  

Given a rectangular pizza represented as a `rows x cols` matrix containing the following characters: `'A'` (an apple) and `'.'` (empty cell) and given the integer `k`. You have to cut the pizza into `k` pieces using `k-1` cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

_Return the number of ways of cutting the pizza such that each piece contains **at least** one apple._ Since the answer can be a huge number, return this modulo 10^9 + 7.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/04/23/ways_to_cut_apple_1.png)**

**Input:** pizza = \["A..","AAA","..."\], k = 3
**Output:** 3 
**Explanation:** The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

**Example 2:**

**Input:** pizza = \["A..","AA.","..."\], k = 3
**Output:** 1

**Example 3:**

**Input:** pizza = \["A..","A..","..."\], k = 1
**Output:** 1

**Constraints:**

*   `1 <= rows, cols <= 50`
*   `rows == pizza.length`
*   `cols == pizza[i].length`
*   `1 <= k <= 10`
*   `pizza` consists of characters `'A'` and `'.'` only.  



**Solution:**  

```cpp
class Solution {
public:
    int m = 0;
    int n = 0;
    long long dp[51][51][11];
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int> > apples(m + 1, vector<int>(n + 1));
        for(int i = 0; i < pizza.size(); ++i) {
            for(int j = 0; j < pizza[0].size(); ++j) {
                apples[i + 1][j + 1] = (pizza[i][j] == 'A') + apples[i][j + 1] + apples[i+1][j] - apples[i][j];
            }
        }
        return helper(apples, pizza, 0, 0, k-1);
    }
    
    bool hasApple(vector<vector<int> > &apples, int x, int y, int x1, int y1) {
        return (apples[x1 + 1] [y1 + 1] - apples[x][y1 + 1] -  apples[x1+1][y] + apples[x][y]) > 0;
    }
    long long helper(vector<vector<int> > &apples, vector<string> &pizza, int x, int y, int k) {
        if(k == 0) {
            return hasApple(apples, x, y, m - 1, n - 1);
        }
        if(dp[x][y][k] >= 0) return dp[x][y][k];
        long long res = 0;
        for(int i = x; i < m - 1; ++i) {
            res += helper(apples, pizza, i + 1, y, k - 1) * hasApple(apples, x, y, i, n - 1);
        }
        for(int j = y; j < n - 1; ++j) {
            res += helper(apples, pizza, x, j + 1, k - 1) * hasApple(apples, x, y, m - 1, j);
        }
        res %= 1000000007;
        return dp[x][y][k] = res;
    }
};
```
      