[573.squirrel-simulation](https://leetcode.com/problems/squirrel-simulation/)  

There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the **minimal** distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most **one nut** at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

**Example 1:**

**Input:** 
Height : 5
Width : 7
Tree position : \[2,2\]
Squirrel : \[4,4\]
Nuts : \[\[3,0\], \[2,5\]\]
**Output:** 12
**Explanation:**
![](https://assets.leetcode.com/uploads/2018/10/22/squirrel_simulation.png)​​​​​

**Note:**

1.  All given positions won't overlap.
2.  The squirrel can take at most one nut at one time.
3.  The given positions of nuts have no order.
4.  Height and width are positive integers. 3 <= height \* width <= 10,000.
5.  The given positions contain at least one nut, only one tree and one squirrel.  



**Solution:**  

```cpp
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int res = 0, mxDiff = INT_MIN, idx = 0;
        for (auto nut : nuts) {
            int dist = abs(tree[0] - nut[0]) + abs(tree[1] - nut[1]);
            res += 2 * dist;
            mxDiff = max(mxDiff, dist - abs(squirrel[0] - nut[0]) - abs(squirrel[1] - nut[1]));
        }
        return res - mxDiff;
    }
};
```
      