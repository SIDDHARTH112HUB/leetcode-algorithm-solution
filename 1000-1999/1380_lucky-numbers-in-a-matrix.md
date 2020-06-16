[1380.lucky-numbers-in-a-matrix](https://leetcode.com/problems/lucky-numbers-in-a-matrix/)  

Given a `m * n` matrix of **distinct** numbers, return all lucky numbers in the matrix in **any** order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

**Example 1:**

  
**Input:** matrix = \[\[3,7,8\],\[9,11,13\],\[15,16,17\]\]
  
**Output:** \[15\]
  
**Explanation:** 15 is the only lucky number since it is the minimum in its row and the maximum in its column
  

**Example 2:**

  
**Input:** matrix = \[\[1,10,4,2\],\[9,3,8,7\],\[15,16,17,12\]\]
  
**Output:** \[12\]
  
**Explanation:** 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
  

**Example 3:**

  
**Input:** matrix = \[\[7,8\],\[1,2\]\]
  
**Output:** \[7\]
  

**Constraints:**

*   `m == mat.length`
*   `n == mat[i].length`
*   `1 <= n, m <= 50`
*   `1 <= matrix[i][j] <= 10^5`.
*   All elements in the matrix are distinct.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int f = true;
                int num  = matrix[i][j];
                for(int k = 0; k < m; ++k) {
                    if(matrix[k][j] > num) {
                        f = false;break;
                    }
                }
                for(int k = 0; k < n; ++k) {
                    if(matrix[i][k] < num) {
                        f = false;break;
                    }
                }
                if(f ) ans.push_back(num);
            }
        }
        return ans;
    }
};
```
      