[1259.handshakes-that-dont-cross](https://leetcode.com/problems/handshakes-that-dont-cross/)  

You are given an **even** number of people `num_people` that stand around a circle and each person shakes hands with someone else, so that there are `num_people / 2` handshakes total.

Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since this number could be very big, return the answer **mod `10^9 + 7`**

**Example 1:**

**Input:** num\_people = 2
**Output:** 1

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/07/11/5125_example_2.png)

**Input:** num\_people = 4
**Output:** 2
**Explanation:** There are two ways to do it, the first way is \[(1,2),(3,4)\] and the second one is \[(2,3),(4,1)\].

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/07/11/5125_example_3.png)

**Input:** num\_people = 6
**Output:** 5

**Example 4:**

**Input:** num\_people = 8
**Output:** 14

**Constraints:**

*   `2 <= num_people <= 1000`
*   `num_people % 2 == 0`  



**Solution:**  

```cpp
class Solution {
public:
    int M = 1e9+7;
    unordered_map<int, int> m;
    int numberOfWays(int num_people) {
        m[1] = 1;
        return h(1, num_people);
    }
    
    long long h(int l, int r) {
        if(r - l == 1) return 1;
        if(l >= r) return 1;
        if((r-l) % 2 == 0) return 0;
        if(m.count(r-l)) return m[r-l];
        long long res = 0;
        for(int i = l + 1; i <= r; i += 2) {
            res += ( h(l + 1, i - 1) * h(i+1, r)) %M;
        }
        m[r-l] = res %M;
        return res %M;
    }
};
```
      