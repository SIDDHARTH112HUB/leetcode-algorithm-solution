[1140.stone-game-ii](https://leetcode.com/problems/stone-game-ii/)  

Alex and Lee continue their games with piles of stones.  There are a number of piles **arranged in a row**, and each pile has a positive integer number of stones `piles[i]`.  The objective of the game is to end with the most stones. 

Alex and Lee take turns, with Alex starting first.  Initially, `M = 1`.

On each player's turn, that player can take **all the stones** in the **first** `X` remaining piles, where `1 <= X <= 2M`.  Then, we set `M = max(M, X)`.

The game continues until all the stones have been taken.

Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.

**Example 1:**

  
**Input:** piles = \[2,7,9,4,4\]
  
**Output:** 10
  
**Explanation:**  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
  

**Constraints:**

*   `1 <= piles.length <= 100`
*   `1 <= piles[i] <= 10 ^ 4`  



**Solution:**  

```cpp
class Solution {
public:
    map<pair<int, int>, int > m;
    int stoneGameII(vector<int>& piles) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return (sum + helper(piles, 0, 1)) / 2;
    }
    
    int helper(vector<int>& piles, int idx, int M) {
        if(idx >= piles.size()) return 0;
        if(m.count( {idx, M})) return m[{idx, M}];
        int ans = INT_MIN;
        int x = -1;
        int sum = 0;
        for(int X = 1; X <= 2 *M && idx + X <= piles.size(); ++X ) {
            sum += piles[idx + X - 1];
            int res = helper(piles, idx + X, max(M, X));
            ans = max(ans, sum - res);
        }
        m[{idx, M}] = ans;
        return ans;
    }
};
```
      