[1007.minimum-domino-rotations-for-equal-row](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/)  

In a row of dominoes, `A[i]` and `B[i]` represent the top and bottom halves of the `i`\-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the `i`\-th domino, so that `A[i]` and `B[i]` swap values.

Return the minimum number of rotations so that all the values in `A` are the same, or all the values in `B` are the same.

If it cannot be done, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/03/08/domino.png)

  
**Input:** A = \[2,1,2,4,2,2\], B = \[5,2,6,2,3,2\]
  
**Output:** 2
  
**Explanation:** 
  
The first figure represents the dominoes as given by A and B: before we do any rotations.
  
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
  

**Example 2:**

  
**Input:** A = \[3,5,1,2,3\], B = \[3,6,3,3,4\]
  
**Output:** \-1
  
**Explanation:** 
  
In this case, it is not possible to rotate the dominoes to make one row of values equal.
  

**Note:**

1.  `1 <= A[i], B[i] <= 6`
2.  `2 <= A.length == B.length <= 20000`  



**Solution:**  

```cpp
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        for(int i = 1; i <= 6; ++i) {
            int cnt = 0;
            int total = 0;
            for(int j = 0; j < A.size(); ++j) {
                if(A[j] == i && B[j] == i) continue;
                if(A[j] != i && B[j] != i){
                   cnt = -1;
                    break;
                }
                ++total;
                if(A[j] == i)
                    ++cnt;
            }
            if(cnt >= 0)
                ans = min(ans, min(cnt, total - cnt));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```
      