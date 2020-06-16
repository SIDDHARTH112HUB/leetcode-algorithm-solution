[650.2-keys-keyboard](https://leetcode.com/problems/2-keys-keyboard/)  

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

1.  `Copy All`: You can copy all the characters present on the notepad (partial copy is not allowed).
2.  `Paste`: You can paste the characters which are copied **last time**.

Given a number `n`. You have to get **exactly** `n` 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get `n` 'A'.

**Example 1:**

  
**Input:** 3
  
**Output:** 3
  
**Explanation:**
  
Intitally, we have one character 'A'.
  
In step 1, we use **Copy All** operation.
  
In step 2, we use **Paste** operation to get 'AA'.
  
In step 3, we use **Paste** operation to get 'AAA'.
  

**Note:**

1.  The `n` will be in the range \[1, 1000\].  



**Solution:**  

```cpp
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1] = {0};
        dp[1] = 0;
        for( int i = 2; i<=n; i++){
            dp[i] = i;
            for( int j = 2; j<= sqrt(n); j++){
                if( i%j == 0 ){
                    dp[i] = dp[i/j] + j;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```
      