[967.numbers-with-same-consecutive-differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)  

Return all **non-negative** integers of length `N` such that the absolute difference between every two consecutive digits is `K`.

Note that **every** number in the answer **must not** have leading zeros **except** for the number `0` itself. For example, `01` has one leading zero and is invalid, but `0` is valid.

You may return the answer in any order.

**Example 1:**

**Input:** N = 3, K = 7
**Output:** \[181,292,707,818,929\]
**Explanation:** Note that 070 is not a valid number, because it has leading zeroes.

**Example 2:**

**Input:** N = 2, K = 1
**Output:** \[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98\]

**Note:**

1.  `1 <= N <= 9`
2.  `0 <= K <= 9`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int N, int K) {
        if( N== 1) {
            //if( K == 0 )
                return {0,1,2,3,4,5,6,7,8,9};   
            //return {};
        }
        
        for( int i = 1; i<=9; i++ ){
            dfs(i, N-1, K);
        }
        return ans;
    }
    
    void dfs( int num, int N, int K){
        if( N == 0 ) {
            ans.push_back(num);
            return;
        }
        if( num % 10 + K <= 9 ){
            dfs(num*10 +num % 10 + K, N-1, K );
        }
        if( num % 10 - K >=0 && K > 0 ){
            dfs(num*10 +num % 10 - K, N-1, K );
        }
    }
};
```
      