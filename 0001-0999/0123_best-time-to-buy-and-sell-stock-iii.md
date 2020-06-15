[123.best-time-to-buy-and-sell-stock-iii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)  

Say you have an array for which the _i_th element is the price of a given stock on day _i_.

Design an algorithm to find the maximum profit. You may complete at most _two_ transactions.

**Note:** You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**Example 1:**

**Input:** \[3,3,5,0,0,3,1,4\]
**Output:** 6
**Explanation:** Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

**Example 2:**

**Input:** \[1,2,3,4,5\]
**Output:** 4
**Explanation:** Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

**Example 3:**

**Input:** \[7,6,4,3,1\]
**Output:** 0
**Explanation:** In this case, no transaction is done, i.e. max profit = 0.  



**Solution:**  

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=INT_MIN,b2=INT_MIN,s1=0,s2=0;
        int buy[2] = {INT_MIN, INT_MIN}, sell[2] = {0};
        for( int i = 0; i<prices.size(); i++ ){ 
            int p = prices[i];
            for(int j = 0; j < 2; ++j ) {
                buy[j] = max(buy[j], (j > 0 ?sell[j-1]:0) - p);
                sell[j] = max(sell[j], buy[j] + p);
            }
            b1 = max(b1, 0 - p );
            s1 = max(s1, b1 + p);
            b2 = max(b2, s1 - p);
            s2 = max(s2, b2 + p);
        }
        return sell[1];
        return s2;
    }
};
```
      