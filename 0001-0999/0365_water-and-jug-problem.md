[365.water-and-jug-problem](https://leetcode.com/problems/water-and-jug-problem/)  

You are given two jugs with capacities _x_ and _y_ litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly _z_ litres using these two jugs.

If _z_ liters of water is measurable, you must have _z_ liters of water contained within **one or both buckets** by the end.

Operations allowed:

*   Fill any of the jugs completely with water.
*   Empty any of the jugs.
*   Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

**Example 1:** (From the famous [_"Die Hard"_ example](https://www.youtube.com/watch?v=BVtQNK_ZUJg))

Input: x = 3, y = 5, z = 4
Output: True

**Example 2:**

Input: x = 2, y = 6, z = 5
Output: False  



**Solution:**  

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x+ y >= z && (z % gcd(x, y) == 0 ));
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
```
      