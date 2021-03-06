[1056.confusing-number](https://leetcode.com/problems/confusing-number/)  

Given a number `N`, return `true` if and only if it is a _confusing number_, which satisfies the following condition:

We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A _confusing number_ is a number that when rotated 180 degrees becomes a **different** number with each digit valid.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/03/23/1268_1.png)

  
**Input:** 6
  
**Output:** true
  
**Explanation:** 
  
We get `9` after rotating `6`, `9` is a valid number and `9!=6`.
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/03/23/1268_2.png)

  
**Input:** 89
  
**Output:** true
  
**Explanation:** 
  
We get `68` after rotating `89`, `86` is a valid number and `86!=89`.
  

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/03/26/1268_3.png)

  
**Input:** 11
  
**Output:** false
  
**Explanation:** 
  
We get `11` after rotating `11`, `11` is a valid number but the value remains the same, thus `11` is not a confusing number.
  

**Example 4:**

![](https://assets.leetcode.com/uploads/2019/03/23/1268_4.png)

  
**Input:** 25
  
**Output:** false
  
**Explanation:** 
  
We get an invalid number after rotating `25`.
  

**Note:**

1.  `0 <= N <= 10^9`
2.  After the rotation we can ignore leading zeros, for example if after rotation we have `0008` then this number is considered as just `8`.  



**Solution:**  

```cpp
class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map<int, int> m{{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        int rotate = 0;
        int temp = N;
        while (temp != 0) {
            int mod = temp % 10;
            if (!m.count(mod))
                return false;
            rotate = 10 * rotate + m[mod];
            temp /= 10;
        }
        return rotate != N;
    }
};
```
      