[861.score-after-flipping-matrix](https://leetcode.com/problems/score-after-flipping-matrix/)  

We have a two dimensional matrix `A` where each value is `0` or `1`.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all `0`s to `1`s, and all `1`s to `0`s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

**Example 1:**

**Input:** \[\[0,0,1,1\],\[1,0,1,0\],\[1,1,0,0\]\]
**Output:** 39
**Explanation:** Toggled to \[\[1,1,1,1\],\[1,0,0,1\],\[1,1,1,1\]\].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

**Note:**

1.  `1 <= A.length <= 20`
2.  `1 <= A[0].length <= 20`
3.  `A[i][j]` is `0` or `1`.  



**Solution:**  

```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        vector<int> ans;
        int m = A.size();
        int n = A[0].size();
        for( int i = 0; i<m; i++){   // 1. flip by row
            int num1 = 0;
            int num2 = 0;
            for( int j = 0; j<n;j++){
                num1 |= A[i][j]<<(n-j-1);
                num2 |= (!A[i][j])<<(n-j-1);
            }
            if( num2 > num1 )
                num1 = num2;
            ans.push_back(num1);
        }
        for( int j = 0; j <n;j++){  // 2. flip by column
            int one = 0, zero=0;
            for( int i = 0; i<m;i++){
                int num = ans[i] & (0x01 <<j);
                if( num == 0 )
                    zero++;
                else
                    one++;
            }
            if( zero>one){
                for( int i = 0; i<m;i++){
                    int num = ans[i] & (0x01 <<j);
                    if( num == 0 ){
                        ans[i] |= 0x01 <<j;
                    }else{
                        ans[i] &= ((0x01<<j)^(0xFFFFFFFF));
                    }
                }
            }
        }
        int total = 0;
        for( int i = 0; i<ans.size(); i++)
            total += ans[i];
        return total;
    }
};
```
      