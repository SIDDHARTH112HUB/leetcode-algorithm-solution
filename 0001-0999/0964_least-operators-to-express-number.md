[964.least-operators-to-express-number](https://leetcode.com/problems/least-operators-to-express-number/)  

Given a single positive integer `x`, we will write an expression of the form `x (op1) x (op2) x (op3) x ...` where each operator `op1`, `op2`, etc. is either addition, subtraction, multiplication, or division (`+`, `-`, `*`, or `/)`.  For example, with `x = 3`, we might write `3 * 3 / 3 + 3 - 3` which is a value of 3.

When writing such an expression, we adhere to the following conventions:

1.  The division operator (`/`) returns rational numbers.
2.  There are no parentheses placed anywhere.
3.  We use the usual order of operations: multiplication and division happens before addition and subtraction.
4.  It's not allowed to use the unary negation operator (`-`).  For example, "`x - x`" is a valid expression as it only uses subtraction, but "`-x + x`" is not because it uses negation.

We would like to write an expression with the least number of operators such that the expression equals the given `target`.  Return the least number of operators used.

**Example 1:**

  
**Input:** x = 3, target = 19
  
**Output:** 5
  
**Explanation:** 3 \* 3 + 3 \* 3 + 3 / 3.  The expression contains 5 operations.
  

**Example 2:**

  
**Input:** x = 5, target = 501
  
**Output:** 8
  
**Explanation:** 5 \* 5 \* 5 \* 5 - 5 \* 5 \* 5 + 5 / 5.  The expression contains 8 operations.
  

**Example 3:**

  
**Input:** x = 100, target = 100000000
  
**Output:** 3
  
**Explanation:** 100 \* 100 \* 100 \* 100.  The expression contains 3 operations.

**Note:**

*   `2 <= x <= 100`
*   `1 <= target <= 2 * 10^8`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, int> m;
    int leastOpsExpressTarget(int x, int target) {
        if( m.count(target )) return m[target];
        if( x > target ){
            return min( target*2-1, (x - target)*2  );
        }
        long long sum  = x;
        int ans = 0;
        while( sum < target){
            sum *= x;
            ++ans;
        }
        if( sum == target ) return ans;
        int l = INT_MAX, r = INT_MAX;
        if( sum - target < target ){
            l = leastOpsExpressTarget(x, sum - target);
        }
        r = leastOpsExpressTarget(x, target-sum/x)-1;
        m[target] = min(l, r) + ans+1;
        return m[target];
    }
};
```
      