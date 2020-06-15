[351.android-unlock-patterns](https://leetcode.com/problems/android-unlock-patterns/)  

Given an Android **3x3** key lock screen and two integers **m** and **n**, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of **m** keys and maximum **n** keys.

**Rules for a valid pattern:**

1.  Each pattern must connect at least **m** keys and at most **n** keys.
2.  All the keys must be distinct.
3.  If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
4.  The order of keys used matters.

![](https://assets.leetcode.com/uploads/2018/10/12/android-unlock.png)

**Explanation:**

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |

**Invalid move:** `4 - 1 - 3 - 6`  
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

**Invalid move:** `4 - 1 - 9 - 2`  
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

**Valid move:** `2 - 4 - 1 - 3 - 6`  
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

**Valid move:** `6 - 5 - 4 - 1 - 9 - 2`  
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

**Example:**

**Input:** m = 1, n = 1
**Output:** 9  



**Solution:**  

```cpp
class Solution {
public:
    int ans = 0;
    int numberOfPatterns(int m, int n) {
        set<int> v;
        dfs(0, m, n, v);
        return ans;
    }
    
    void dfs(int s, int m, int n, set<int> &v) {
        if(v.count(s)) return;
        if(m <= 0) ++ans;
        if(n <= 0) {
            return;
        }
        v.insert(s);
        for(int i = 1; i <=9; ++i) {
            if(s + i == 10 && v.count(5) == 0) continue;
            if(min(s, i) == 1 && max(s, i) == 3 && v.count(2) == 0) continue;
            if(min(s, i) == 7 && max(s, i) == 9 && v.count(8) == 0) continue;
            if(min(s, i) == 3 && max(s, i) == 9 && v.count(6) == 0) continue;
            if(min(s, i) == 1 && max(s, i) == 7 && v.count(4) == 0) continue;
            dfs(i, m - 1, n - 1, v);
        }
        v.erase(s);
    }
};
```
      