[1128.number-of-equivalent-domino-pairs](https://leetcode.com/problems/number-of-equivalent-domino-pairs/)  

Given a list of `dominoes`, `dominoes[i] = [a, b]` is _equivalent_ to `dominoes[j] = [c, d]` if and only if either (`a==c` and `b==d`), or (`a==d` and `b==c`) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs `(i, j)` for which `0 <= i < j < dominoes.length`, and `dominoes[i]` is equivalent to `dominoes[j]`.

**Example 1:**

**Input:** dominoes = \[\[1,2\],\[2,1\],\[3,4\],\[5,6\]\]
**Output:** 1

**Constraints:**

*   `1 <= dominoes.length <= 40000`
*   `1 <= dominoes[i][j] <= 9`  



**Solution:**  

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        int ans = 0;
        for(auto &d : dominoes) {
            int a = d[0];
            int b = d[1];
            int ab = a*10 +b;
            int ba = b *10 + a;
            if(m.count(ab) || m.count(ba))
                ans += m[ab];
            ++m[ab];
            if(ab != ba)
                ++m[ba];
        }
        return ans;
    }
    
};
```
      