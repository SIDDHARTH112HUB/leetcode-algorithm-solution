[1563.stone-game-v](https://leetcode.com/problems/stone-game-v/)  

There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

In each round of the game, Alice divides the row into **two non-empty rows** (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only **one stone remaining**. Alice's is initially **zero**.

Return _the maximum score that Alice can obtain_.

**Example 1:**

  
**Input:** stoneValue = \[6,2,3,4,5,5\]  
**Output:** 18  
**Explanation:** In the first round, Alice divides the row to \[6,2,3\], \[4,5,5\]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.  
In the second round Alice divides the row to \[6\], \[2,3\]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).  
The last round Alice has only one choice to divide the row which is \[2\], \[3\]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.  

**Example 2:**

  
**Input:** stoneValue = \[7,7,7,7,7,7,7\]  
**Output:** 28  

**Example 3:**

  
**Input:** stoneValue = \[4\]  
**Output:** 0  

**Constraints:**

*   `1 <= stoneValue.length <= 500`
*   `1 <= stoneValue[i] <= 10^6`  



**Solution:**  

```cpp
class Solution {
public:
    int dp[501][501];
    int dfs(vector<int>& sv, int l, int r) {
        if(l >= r) return 0;
        if(dp[l][r] >= 0) return dp[l][r];
        int res = 0;
        for(int i = l; i <r ; ++i) {
            int lv = sv[i] - (l > 0 ? sv[l - 1] : 0);
            int rv = sv[r] - sv[i];
            if(lv > rv) res = max(res, dfs(sv, i + 1, r) + rv);
            else if(lv < rv) res = max(res, dfs(sv, l, i) + lv);
            else {
                res = max({res, dfs(sv, i + 1, r) + rv,  dfs(sv, l, i) + lv});
            }
            
        }
        return dp[l][r] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp, -1, sizeof(dp));
        if(stoneValue.size() == 1) return 0;
        for(int i = 1; i < stoneValue.size(); ++i) stoneValue[i] += stoneValue[i - 1];
        return dfs(stoneValue, 0, stoneValue.size() - 1);
    }
};
```
      