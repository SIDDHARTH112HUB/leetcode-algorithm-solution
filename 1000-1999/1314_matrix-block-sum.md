[1314.matrix-block-sum](https://leetcode.com/problems/matrix-block-sum/)  

Given a `m * n` matrix `mat` and an integer `K`, return a matrix `answer` where each `answer[i][j]` is the sum of all elements `mat[r][c]` for `i - K <= r <= i + K, j - K <= c <= j + K`, and `(r, c)` is a valid position in the matrix.

**Example 1:**

  
**Input:** mat = \[\[1,2,3\],\[4,5,6\],\[7,8,9\]\], K = 1
  
**Output:** \[\[12,21,16\],\[27,45,33\],\[24,39,28\]\]
  

**Example 2:**

  
**Input:** mat = \[\[1,2,3\],\[4,5,6\],\[7,8,9\]\], K = 2
  
**Output:** \[\[45,45,45\],\[45,45,45\],\[45,45,45\]\]
  

**Constraints:**

*   `m == mat.length`
*   `n == mat[i].length`
*   `1 <= m, n, K <= 100`
*   `1 <= mat[i][j] <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; ++i) {
            int sum = 0;
            for(int j = 0; j < n; ++j) {
                int t = mat[i][j];
                mat[i][j] += (i > 0 ? mat[i-1][j] : 0) + sum;
                //cout<<mat[i][j]<<" ";
                sum += t;
            }
            //cout<<endl;
        }
        vector<vector<int> > ans(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int lx = max(i - K, 0), rx = min(m-1, i + K);
                int ly = max(j - K, 0), ry = min(n-1, j + K);
                ans[i][j] = mat[rx][ry] + ((lx > 0 && ly> 0) ? mat[lx-1][ly-1]:0) - (ly > 0 ? mat[rx][ly-1]:0) - (lx > 0 ? mat[lx-1][ry]:0);
            }
        }
        return ans;
    }
};
```
      