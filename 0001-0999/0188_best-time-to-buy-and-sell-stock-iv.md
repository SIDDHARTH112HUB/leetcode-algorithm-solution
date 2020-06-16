[188.best-time-to-buy-and-sell-stock-iv](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)  

Say you have an array for which the _i\-_th element is the price of a given stock on day _i_.

Design an algorithm to find the maximum profit. You may complete at most **k** transactions.

**Note:**  
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

**Example 1:**

  
**Input:** \[2,4,1\], k = 2  
**Output:** 2  
**Explanation:** Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.  

**Example 2:**

  
**Input:** \[3,2,6,5,0,3\], k = 2  
**Output:** 7  
**Explanation:** Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.  
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.  



**Solution:**  

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if( k <= 0 ) return 0;
        int n = prices.size();
        if( n <= 1) return 0;
        if( k > n/2) k = n/2+1;
        int b[k], s[k] = {0};
        
        
        
        for( int i = 0; i< k; i++)
            b[i] = INT_MIN;
        for( int i = 0; i<n; i++){
            int p = prices[i];
            //b[0] = max(b[0], 0 - p);
            //s[0] = max(b[0] + p, s[0]);
            for( int j = 0; j<k; j++){
                b[j] = max( b[j], ( j> 0?s[j-1]:0) - p);
                s[j] = max( b[j] + p, s[j]);
            }
        }
        return s[k-1];
    }
};
```
      