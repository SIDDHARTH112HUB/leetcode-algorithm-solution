[322.coin-change](https://leetcode.com/problems/coin-change/)  

You are given coins of different denominations and a total amount of money _amount_. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

**Example 1:**

**Input:** coins = `[1, 2, 5]`, amount = `11`
**Output:** `3` 
**Explanation:** 11 = 5 + 5 + 1

**Example 2:**

**Input:** coins = `[2]`, amount = `3`
**Output:** \-1

**Note**:  
You may assume that you have an infinite number of each kind of coin.  



**Solution:**  

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i<coins.size(); i++){
            if( coins[i] > amount )
                continue;
            for( int j=coins[i];j<=amount; j++){
                if(dp[j - coins[i]] >= 0){
                    dp[j] = min(dp[j-coins[i]]+1, dp[j] == -1 ? INT_MAX : dp[j]);
                }
            }
        }
        return dp[amount];
    }
};
```
      