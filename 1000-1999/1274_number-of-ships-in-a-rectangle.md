[1274.number-of-ships-in-a-rectangle](https://leetcode.com/problems/number-of-ships-in-a-rectangle/)  

_(This problem is an **interactive problem**.)_

On the sea represented by a cartesian plane, each ship is located at an integer point, and each integer point may contain at most 1 ship.

You have a function `Sea.hasShips(topRight, bottomLeft)` which takes two points as arguments and returns `true` if and only if there is at least one ship in the rectangle represented by the two points, including on the boundary.

Given two points, which are the top right and bottom left corners of a rectangle, return the number of ships present in that rectangle.  It is guaranteed that there are **at most 10 ships** in that rectangle.

Submissions making **more than 400 calls** to `hasShips` will be judged _Wrong Answer_.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

**Example :**

![](https://assets.leetcode.com/uploads/2019/07/26/1445_example_1.PNG)

**Input:** 
ships = \[\[1,1\],\[2,2\],\[3,3\],\[5,5\]\], topRight = \[4,4\], bottomLeft = \[0,0\]
**Output:** 3
**Explanation:** From \[0,0\] to \[4,4\] we can count 3 ships within the range.

**Constraints:**

*   On the input `ships` is only given to initialize the map internally. You must solve this problem "blindfolded". In other words, you must find the answer using the given `hasShips` API, without knowing the `ships` position.
*   `0 <= bottomLeft[0] <= topRight[0] <= 1000`
*   `0 <= bottomLeft[1] <= topRight[1] <= 1000`  



**Solution:**  

```cpp
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int top = topRight[0], right = topRight[1], bottom = bottomLeft[0], left = bottomLeft[1];
        if(left > right || bottom > top) return 0;
        int res = sea.hasShips(topRight, bottomLeft);
        if((top == bottom && left == right) || res == 0) return res;
        return countShips(sea,  {top, (left + right)/2}, {(bottom + top)/2+1, left} ) + countShips(sea,  {top, right}, {(bottom + top)/2 + 1, (left +right) / 2 + 1} ) + countShips(sea,  {(top + bottom)/2, (left+right)/2}, {bottom, left } ) + countShips(sea,  {(top + bottom)/2, right}, {bottom, (left+right)/2 + 1 }  );
    }
    
    
};
```
      