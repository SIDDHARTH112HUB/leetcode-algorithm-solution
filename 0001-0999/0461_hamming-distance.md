[461.hamming-distance](https://leetcode.com/problems/hamming-distance/)  

The [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, calculate the Hamming distance.

**Note:**  
0 ≤ `x`, `y` < 231.

**Example:**

**Input:** x = 1, y = 4

**Output:** 2

**Explanation:**
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.  



**Solution:**  

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        uint32_t a =x, b=y;
        while( a>0 ||b>0){
            ans += (a & 0x1) ^ (b&0x01);
            a = a>>1;
            b = b>>1;
        }
        return ans;
    }
};
```
      