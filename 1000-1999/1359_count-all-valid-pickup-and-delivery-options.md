[1359.count-all-valid-pickup-and-delivery-options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/)  

Given `n` orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

**Example 1:**

  
**Input:** n = 1
  
**Output:** 1
  
**Explanation:** Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
  

**Example 2:**

  
**Input:** n = 2
  
**Output:** 6
  
**Explanation:** All possible orders: 
  
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
  
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
  

**Example 3:**

  
**Input:** n = 3
  
**Output:** 90
  

**Constraints:**

*   `1 <= n <= 500`  



**Solution:**  

```cpp
class Solution {
public:
    map<int, int> m;
    long long M = 1e9 + 7;
    vector<long long> p;
    int countOrders(int n) {
        n *= 2;
        p.resize(n + 1);
        vector<int> dp(n+1);
        p[0] = 0;
        //cout<<endl;
        for(int i = 1; i <=n; ++i) {
            p[i] = p[i-1] + i;
            //cout<<p[i]<<endl;
        }
        return dfs(n);
    }
    long long dfs(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        if(m.count(n)) return m[n];
        long long sum = (p[n-1] * dfs(n - 2)) %M;
        m[n] = sum;
        return sum;
    }
};
```
      