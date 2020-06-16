[935.knight-dialer](https://leetcode.com/problems/knight-dialer/)  

A chess knight can move as indicated in the chess diagram below:

![](https://assets.leetcode.com/uploads/2018/10/12/knight.png) .           ![](https://assets.leetcode.com/uploads/2018/10/30/keypad.png)

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes `N-1` hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing `N` digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, **output the answer modulo `10^9 + 7`**.

**Example 1:**

  
**Input:** 1
  
**Output:** 10
  

**Example 2:**

  
**Input:** 2
  
**Output:** 20
  

**Example 3:**

  
**Input:** 3
  
**Output:** 46
  

**Note:**

*   `1 <= N <= 5000`  



**Solution:**  

```cpp
class Solution {
public:
    int knightDialer(int N) {
        int dp[N][10] = {0};
        for( int i = 0; i<10; i++){
            dp[0][i] = 1;
        }
        int M = 1000000007;
        unordered_map<int, vector<int> > m;
        m[0] = {4, 6};
        m[1] = {8, 6};
        m[2] = {7, 9};
        m[3] = {4, 8};
        m[4] = {0, 9, 3};
        m[6] = {1, 7, 0};
        m[7] = {2, 6};
        m[8] = {1, 3};
        m[9] = {4, 2};
        if( N == 1 ) return 10;
        for( int n = 1; n < N; n++){
            for( int i = 0; i<10; i++){
                if( i == 5 )continue;
                for( int t : m[i]){
                    dp[n][i] += dp[n-1][t];
                    dp[n][i] %= M;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < 10; i++){
            ans += dp[N-1][i];
            ans %= M;
        }
        return ans;
    }
};
```
      