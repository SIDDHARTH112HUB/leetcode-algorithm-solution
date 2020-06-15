[1344.angle-between-hands-of-a-clock](https://leetcode.com/problems/angle-between-hands-of-a-clock/)  

Given two numbers, `hour` and `minutes`. Return the smaller angle (in degrees) formed between the `hour` and the `minute` hand.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/12/26/sample_1_1673.png)

**Input:** hour = 12, minutes = 30
**Output:** 165

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/12/26/sample_2_1673.png)

**Input:** hour = 3, minutes = 30
**Output:** 75

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/12/26/sample_3_1673.png)**

**Input:** hour = 3, minutes = 15
**Output:** 7.5

**Example 4:**

**Input:** hour = 4, minutes = 50
**Output:** 155

**Example 5:**

**Input:** hour = 12, minutes = 0
**Output:** 0

**Constraints:**

*   `1 <= hour <= 12`
*   `0 <= minutes <= 59`
*   Answers within `10^-5` of the actual value will be accepted as correct.  



**Solution:**  

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = minutes / 60.0 * 360;
        double b = (hour  % 12) / 12.0 *360 + (minutes/60.0/12.0 * 360);
        //cout<<a<<" "<<b<<endl;
        double ang = fabs(a - b);
        if(ang > 180) return 360 - ang;
        return ang;
    }
};
```
      