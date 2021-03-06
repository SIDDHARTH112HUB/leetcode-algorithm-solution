[714.best-time-to-buy-and-sell-stock-with-transaction-fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)  

Your are given an array of integers `prices`, for which the `i`\-th element is the price of a given stock on day `i`; and a non-negative integer `fee` representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

**Example 1:**  

  
**Input:** prices = \[1, 3, 2, 8, 4, 9\], fee = 2
  
**Output:** 8
  
**Explanation:** The maximum profit can be achieved by:
  
*   Buying at prices\[0\] = 1
*   Selling at prices\[3\] = 8
*   Buying at prices\[4\] = 4
*   Selling at prices\[5\] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
  

**Note:**

*   `0 < prices.length <= 50000`.
*   `0 < prices[i] < 50000`.
*   `0 <= fee < 50000`.  



**Solution:**  

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if( n <= 1 ) return 0;
        int  buy[n]={0}, sell[n] = {0};
        for( int i = 0; i< n ; i++){
            int p = prices[i];
            buy[i] = max( (i>0?sell[i-1]:0) - p - fee, (i>0? buy[i-1]: INT_MIN) );
            sell[i]= max( (i>0?buy[i-1]:INT_MIN) + p , (i>0? sell[i-1]:0)  );
        }
        return sell[n-1];
    }
};
```
      