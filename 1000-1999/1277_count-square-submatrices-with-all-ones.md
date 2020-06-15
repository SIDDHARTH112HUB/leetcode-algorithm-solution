[1277.count-square-submatrices-with-all-ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)  

Given a `m * n` matrix of ones and zeros, return how many **square** submatrices have all ones.

**Example 1:**

**Input:** matrix =
\[
  \[0,1,1,1\],
  \[1,1,1,1\],
  \[0,1,1,1\]
\]
**Output:** 15
**Explanation:** 
There are **10** squares of side 1.
There are **4** squares of side 2.
There is  **1** square of side 3.
Total number of squares = 10 + 4 + 1 = **15**.

**Example 2:**

**Input:** matrix = 
\[
  \[1,0,1\],
  \[1,1,0\],
  \[1,1,0\]
\]
**Output:** 7
**Explanation:** 
There are **6** squares of side 1.  
There is **1** square of side 2. 
Total number of squares = 6 + 1 = **7**.

**Constraints:**

*   `1 <= arr.length <= 300`
*   `1 <= arr[0].length <= 300`
*   `0 <= arr[i][j] <= 1`  



**Solution:**  

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            int sum = 0;
            for(int j = 0; j < matrix[i].size(); ++j) {
                int t = matrix[i][j];
                if(t == 1) ++ans;
                matrix[i][j] += sum + (i > 0 ? matrix[i-1][j] : 0);
                sum += t;
            }
        }
        int mx = min(matrix.size(), matrix[0].size());
        for(int k = 1; k < mx; ++k ) {
            for(int i = k; i < matrix.size(); ++i) {

                for(int j = k; j < matrix[i].size(); ++j) {
                    int num = matrix[i][j] - (i-k > 0 ? matrix[i-k-1][j]:0) - (j-k > 0 ? matrix[i][j-k-1]:0) + 
                        ((i-k > 0 && j-k > 0) ?matrix[i-k-1][j-k-1]:0);
                    if(num == (k+1) * (k+1)) ++ans;
                }
            }
        }
        return ans;
    }
};
```
      