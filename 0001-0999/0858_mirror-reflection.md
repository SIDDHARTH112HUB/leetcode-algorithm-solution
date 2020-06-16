[858.mirror-reflection](https://leetcode.com/problems/mirror-reflection/)  

There is a special square room with mirrors on each of the four walls.  Except for the southwest corner, there are receptors on each of the remaining corners, numbered `0`, `1`, and `2`.

The square room has walls of length `p`, and a laser ray from the southwest corner first meets the east wall at a distance `q` from the `0`th receptor.

Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will meet a receptor eventually.)

**Example 1:**

  
**Input:** p = 2, q = 1
  
**Output:** 2
  
**Explanation:** The ray meets receptor 2 the first time it gets reflected back to the left wall.
  

![](https://ibb.co/mYSFJT)![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/18/reflection.png)

  

**Note:**

1.  `1 <= p <= 1000`
2.  `0 <= q <= p`  



**Solution:**  

```cpp
class Solution {
public:
    int gcd(int a, int b){
        if( a == 0 || b == 0 ) return a > b ? a : b;
        return a % b ? gcd(b, a%b):b;
    }
    int mirrorReflection(int p, int q) {
        if( p == 0 || q == 0) return 0;
        int lcm = p*q / gcd(p,q);
        int q_cnt = lcm/q;
        int p_cnt = lcm/p;
        if( q_cnt % 2 == 0 ) return 2;
        return  p_cnt % 2;
    }
};
```
      